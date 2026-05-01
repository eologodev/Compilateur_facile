%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>

extern FILE *yyin;
extern int yylex(void);
extern int yylineno;

int yyerror(const char *msg);
void produce_code(GNode *node);

static FILE *stream = NULL;
static FILE *tmp_body = NULL;
static GHashTable *table = NULL;
static char *module_name = NULL;

static int label_counter = 0;

static char *new_label(void) {
    char buf[32];
    snprintf(buf, sizeof(buf), "L_%04d", label_counter++);
    return strdup(buf);
}

#define MAX_LOOP_DEPTH 64
static char *loop_start_labels[MAX_LOOP_DEPTH];
static char *loop_end_labels[MAX_LOOP_DEPTH];
static int loop_depth = 0;

static char *current_if_end_label = NULL;

%}

%union {
    gulong number;
    gchar *string;
    GNode *node;
}

%token <number> TOK_NUMBER "number"
%token <string> TOK_IDENTIFIER "identifier"

%token TOK_IF        "if"
%token TOK_THEN      "then"
%token TOK_ELSE      "else"
%token TOK_ELSEIF    "elseif"
%token TOK_END       "end"
%token TOK_ENDIF     "endif"
%token TOK_WHILE     "while"
%token TOK_DO        "do"
%token TOK_ENDWHILE  "endwhile"
%token TOK_BREAK     "break"
%token TOK_CONTINUE  "continue"
%token TOK_READ      "read"
%token TOK_PRINT     "print"
%token TOK_TRUE      "true"
%token TOK_FALSE     "false"

%token TOK_SEMI_COLON  ";"
%token TOK_AFFECTATION ":="
%token TOK_GEQ ">="
%token TOK_LEQ "<="
%token TOK_GT  ">"
%token TOK_LT  "<"
%token TOK_EQ  "="
%token TOK_NEQ "#"
%token TOK_OPEN_PAR  "("
%token TOK_CLOSE_PAR ")"

%left  TOK_ADD "+"
%left  TOK_SUB "-"
%left  TOK_MUL "*"
%left  TOK_DIV "/"

%left  TOK_OR  "or"
%left  TOK_AND "and"
%right TOK_NOT "not"

%type <node> code
%type <node> instruction
%type <node> affectation
%type <node> read
%type <node> print
%type <node> if_instr
%type <node> elseif_list
%type <node> else_part
%type <node> while_instr
%type <node> code_while
%type <node> expression
%type <node> boolean
%type <node> identifier
%type <node> number

%define parse.error verbose

%%

program:
    code
    {
        guint nb_vars;
        guint i;
        char copy_buf[4096];
        size_t nread;

        produce_code($1);

        nb_vars = g_hash_table_size(table);

        fprintf(stream, ".assembly %s {}\n", module_name);
        fprintf(stream, ".assembly extern mscorlib {}\n");
        fprintf(stream, ".method static void Main()\n");
        fprintf(stream, "{\n");
        fprintf(stream, ".entrypoint\n");
        fprintf(stream, ".maxstack 32\n");
        if (nb_vars > 0) {
            fprintf(stream, ".locals init (");
            for (i = 0; i < nb_vars; i++) {
                if (i > 0) fprintf(stream, ", ");
                fprintf(stream, "int32 V_%u", i);
            }
            fprintf(stream, ")\n");
        }

        rewind(tmp_body);
        while ((nread = fread(copy_buf, 1, sizeof(copy_buf), tmp_body)) > 0)
            fwrite(copy_buf, 1, nread, stream);

        fprintf(stream, "ret\n");
        fprintf(stream, "}\n");
    }
;

code:
    code instruction
    {
        $$ = g_node_new(strdup("code"));
        g_node_append($$, $1);
        g_node_append($$, $2);
    }
    |
    {
        $$ = g_node_new(strdup(""));
    }
;
instruction:
    affectation
    | read
    | print
    | if_instr
    | while_instr
    | TOK_BREAK TOK_SEMI_COLON
    {
        $$ = g_node_new(strdup("break"));
    }
    | TOK_CONTINUE TOK_SEMI_COLON
    {
        $$ = g_node_new(strdup("continue"));
    }
;




affectation:
    identifier TOK_AFFECTATION expression TOK_SEMI_COLON
    {
        $$ = g_node_new(strdup("affectation"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
;

read:
    TOK_READ identifier TOK_SEMI_COLON
    {
        $$ = g_node_new(strdup("read"));
        g_node_append($$, $2);
    }
;

print:
    TOK_PRINT expression TOK_SEMI_COLON
    {
        $$ = g_node_new(strdup("print"));
        g_node_append($$, $2);
    }
;

if_instr:
    TOK_IF boolean TOK_THEN code elseif_list else_part TOK_END
    {
        $$ = g_node_new(strdup("if"));
        g_node_append($$, $2);
        g_node_append($$, $4);
        g_node_append($$, $5);
        g_node_append($$, $6);
    }
    |
    TOK_IF boolean TOK_THEN code elseif_list else_part TOK_ENDIF
    {
        $$ = g_node_new(strdup("if"));
        g_node_append($$, $2);
        g_node_append($$, $4);
        g_node_append($$, $5);
        g_node_append($$, $6);
    }
    
;

elseif_list:
    elseif_list TOK_ELSEIF boolean TOK_THEN code
    {
        GNode *ei = g_node_new(strdup("elseif"));
        g_node_append(ei, $3);
        g_node_append(ei, $5);
        $$ = g_node_new(strdup("elseif_list"));
        g_node_append($$, $1);
        g_node_append($$, ei);
    }
    |
    {
        $$ = g_node_new(strdup("elseif_list_empty"));
    }
;

else_part:
    TOK_ELSE code
    {
        $$ = g_node_new(strdup("else"));
        g_node_append($$, $2);
    }
    |
    {
        $$ = g_node_new(strdup("else_empty"));
    }
;

while_instr:
    TOK_WHILE boolean TOK_DO code_while TOK_END
    {
        $$ = g_node_new(strdup("while"));
        g_node_append($$, $2);
        g_node_append($$, $4);
    }
    |
    TOK_WHILE boolean TOK_DO code_while TOK_ENDWHILE
    {
        $$ = g_node_new(strdup("while"));
        g_node_append($$, $2);
        g_node_append($$, $4);
    }
;

code_while:
    code_while instruction
    {
        $$ = g_node_new(strdup("code_while"));
        g_node_append($$, $1);
        g_node_append($$, $2);
    }
    |
    {
        $$ = g_node_new(strdup(""));
    }
;

expression:
    identifier
    | number
    |
    expression TOK_ADD expression
    {
        $$ = g_node_new(strdup("add"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_SUB expression
    {
        $$ = g_node_new(strdup("sub"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_MUL expression
    {
        $$ = g_node_new(strdup("mul"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_DIV expression
    {
        $$ = g_node_new(strdup("div"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    TOK_OPEN_PAR expression TOK_CLOSE_PAR
    {
        $$ = $2;
    }
;

boolean:
    TOK_TRUE
    {
        $$ = g_node_new(strdup("true"));
    }
    |
    TOK_FALSE
    {
        $$ = g_node_new(strdup("false"));
    }
    |
    expression TOK_GEQ expression
    {
        $$ = g_node_new(strdup("geq"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_LEQ expression
    {
        $$ = g_node_new(strdup("leq"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_GT expression
    {
        $$ = g_node_new(strdup("gt"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_LT expression
    {
        $$ = g_node_new(strdup("lt"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_EQ expression
    {
        $$ = g_node_new(strdup("eq"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    expression TOK_NEQ expression
    {
        $$ = g_node_new(strdup("neq"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    TOK_NOT boolean
    {
        $$ = g_node_new(strdup("not"));
        g_node_append($$, $2);
    }
    |
    boolean TOK_AND boolean
    {
        $$ = g_node_new(strdup("and"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    boolean TOK_OR boolean
    {
        $$ = g_node_new(strdup("or"));
        g_node_append($$, $1);
        g_node_append($$, $3);
    }
    |
    TOK_OPEN_PAR boolean TOK_CLOSE_PAR
    {
        $$ = $2;
    }
;

identifier:
    TOK_IDENTIFIER
    {
        gulong value;
        $$ = g_node_new(strdup("identifier"));
        value = (gulong) g_hash_table_lookup(table, $1);
        if (!value) {
            value = (gulong) g_hash_table_size(table) + 1;
            g_hash_table_insert(table, g_strdup($1), (gpointer) value);
        }
        g_node_append_data($$, (gpointer) value);
        g_free($1);
    }
;

number:
    TOK_NUMBER
    {
        $$ = g_node_new(strdup("number"));
        g_node_append_data($$, (gpointer) $1);
    }
;

%%

int yyerror(const char *msg) {
    fprintf(stderr, "Line %d: %s\n", yylineno, msg);
    return 0;
}

void produce_code(GNode *node) {
    const char *tag;
    GNode *cond, *code_then, *ei_list, *el_part;
    char *lbl_end, *lbl_next, *lbl_skip;
    char *saved_end;
    char *lbl_start, *lbl_end_w;
    gulong idx, val;

    if (!node) return;
    tag = (const char *) node->data;
    if (!tag) return;

    if (strcmp(tag, "code") == 0 || strcmp(tag, "code_while") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
    }
    else if (strcmp(tag, "") == 0) {
        /* vide */
    }
    else if (strcmp(tag, "affectation") == 0) {
        produce_code(g_node_nth_child(node, 1));
        idx = (gulong) g_node_nth_child(g_node_nth_child(node, 0), 0)->data - 1;
        fprintf(tmp_body, "stloc\t%lu\n", idx);
    }
    else if (strcmp(tag, "read") == 0) {
        idx = (gulong) g_node_nth_child(g_node_nth_child(node, 0), 0)->data - 1;
        fprintf(tmp_body, "call string class [mscorlib]System.Console::ReadLine()\n");
        fprintf(tmp_body, "call int32 int32::Parse(string)\n");
        fprintf(tmp_body, "stloc\t%lu\n", idx);
    }
    else if (strcmp(tag, "print") == 0) {
        produce_code(g_node_nth_child(node, 0));
        fprintf(tmp_body, "call void class [mscorlib]System.Console::WriteLine(int32)\n");
    }
    else if (strcmp(tag, "add") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "add\n");
    }
    else if (strcmp(tag, "sub") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "sub\n");
    }
    else if (strcmp(tag, "mul") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "mul\n");
    }
    else if (strcmp(tag, "div") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "div\n");
    }
    else if (strcmp(tag, "number") == 0) {
        val = (gulong) g_node_nth_child(node, 0)->data;
        fprintf(tmp_body, "ldc.i4\t%lu\n", val);
    }
    else if (strcmp(tag, "identifier") == 0) {
        idx = (gulong) g_node_nth_child(node, 0)->data - 1;
        fprintf(tmp_body, "ldloc\t%lu\n", idx);
    }
    else if (strcmp(tag, "if") == 0) {
        saved_end = current_if_end_label;
        lbl_end = new_label();
        lbl_next  = new_label();
        current_if_end_label = lbl_end;

        cond = g_node_nth_child(node, 0);
        code_then = g_node_nth_child(node, 1);
        ei_list = g_node_nth_child(node, 2);
        el_part = g_node_nth_child(node, 3);

        produce_code(cond);
        fprintf(tmp_body, "brfalse\t%s\n", lbl_next);
        produce_code(code_then);
        fprintf(tmp_body, "br\t%s\n", lbl_end);
        fprintf(tmp_body, "%s:\n", lbl_next);
        free(lbl_next);

        produce_code(ei_list);
        produce_code(el_part);

        fprintf(tmp_body, "%s:\n", lbl_end);
        free(lbl_end);

        current_if_end_label = saved_end;
    }
    else if (strcmp(tag, "elseif_list_empty") == 0) {
        /* vide */
    }
    else if (strcmp(tag, "elseif_list") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
    }
    else if (strcmp(tag, "elseif") == 0) {
        lbl_skip = new_label();
        produce_code(g_node_nth_child(node, 0));
        fprintf(tmp_body, "brfalse\t%s\n", lbl_skip);
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "br\t%s\n", current_if_end_label);
        fprintf(tmp_body, "%s:\n", lbl_skip);
        free(lbl_skip);
    }
    else if (strcmp(tag, "else") == 0) {
        produce_code(g_node_nth_child(node, 0));
    }
    else if (strcmp(tag, "else_empty") == 0) {
        /* vide */
    }
    else if (strcmp(tag, "while") == 0) {
        lbl_start = new_label();
        lbl_end_w = new_label();

        if (loop_depth < MAX_LOOP_DEPTH) {
            loop_start_labels[loop_depth] = lbl_start;
            loop_end_labels[loop_depth] = lbl_end_w;
            loop_depth++;
        }

        fprintf(tmp_body, "%s:\n", lbl_start);
        produce_code(g_node_nth_child(node, 0));
        fprintf(tmp_body, "brfalse\t%s\n", lbl_end_w);
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "br\t%s\n", lbl_start);
        fprintf(tmp_body, "%s:\n", lbl_end_w);

        if (loop_depth > 0) {
            loop_depth--;
            free(loop_start_labels[loop_depth]);
            free(loop_end_labels[loop_depth]);
        }
    }
    else if (strcmp(tag, "break") == 0) {
        if (loop_depth > 0)
            fprintf(tmp_body, "br\t%s\n", loop_end_labels[loop_depth - 1]);
        else
            fprintf(stderr, "Erreur : break hors boucle\n");
    }
    else if (strcmp(tag, "continue") == 0) {
        if (loop_depth > 0)
            fprintf(tmp_body, "br\t%s\n", loop_start_labels[loop_depth - 1]);
        else
            fprintf(stderr, "Erreur : continue hors boucle\n");
    }
    else if (strcmp(tag, "true") == 0) {
        fprintf(tmp_body, "ldc.i4\t1\n");
    }
    else if (strcmp(tag, "false") == 0) {
        fprintf(tmp_body, "ldc.i4\t0\n");
    }
    else if (strcmp(tag, "geq") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "clt\n");
        fprintf(tmp_body, "ldc.i4\t0\n");
        fprintf(tmp_body, "ceq\n");
    }
    else if (strcmp(tag, "leq") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "cgt\n");
        fprintf(tmp_body, "ldc.i4\t0\n");
        fprintf(tmp_body, "ceq\n");
    }
    else if (strcmp(tag, "gt") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "cgt\n");
    }
    else if (strcmp(tag, "lt") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "clt\n");
    }
    else if (strcmp(tag, "eq") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "ceq\n");
    }
    else if (strcmp(tag, "neq") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "ceq\n");
        fprintf(tmp_body, "ldc.i4\t0\n");
        fprintf(tmp_body, "ceq\n");
    }
    else if (strcmp(tag, "not") == 0) {
        produce_code(g_node_nth_child(node, 0));
        fprintf(tmp_body, "ldc.i4\t0\n");
        fprintf(tmp_body, "ceq\n");
    }
    else if (strcmp(tag, "and") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "and\n");
    }
    else if (strcmp(tag, "or") == 0) {
        produce_code(g_node_nth_child(node, 0));
        produce_code(g_node_nth_child(node, 1));
        fprintf(tmp_body, "or\n");
    }
}

int main(int argc, char *argv[]) {
    char *file_name_input;
    char *extension;
    char *directory_delimiter;
    char *basename;
    char *onechar;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <fichier.facile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    file_name_input = argv[1];

    extension = rindex(file_name_input, '.');
    if (!extension || strcmp(extension, ".facile") != 0) {
        fprintf(stderr, "L'extension doit etre '.facile'\n");
        return EXIT_FAILURE;
    }

    directory_delimiter = rindex(file_name_input, '/');
    if (!directory_delimiter)
        directory_delimiter = rindex(file_name_input, '\\');
    if (directory_delimiter)
        basename = strdup(directory_delimiter + 1);
    else
        basename = strdup(file_name_input);

    module_name = strdup(basename);
    *rindex(module_name, '.') = '\0';

    onechar = module_name;
    if (!isalpha((unsigned char)*onechar) && *onechar != '_') {
        free(basename); free(module_name);
        fprintf(stderr, "Nom de fichier invalide\n");
        return EXIT_FAILURE;
    }
    onechar++;
    while (*onechar) {
        if (!isalnum((unsigned char)*onechar) && *onechar != '_') {
            free(basename); free(module_name);
            fprintf(stderr, "Nom de fichier invalide\n");
            return EXIT_FAILURE;
        }
        onechar++;
    }

    strcpy(rindex(basename, '.'), ".il");

    yyin = fopen(file_name_input, "r");
    if (!yyin) {
        free(basename); free(module_name);
        fprintf(stderr, "Impossible d'ouvrir '%s'\n", file_name_input);
        return EXIT_FAILURE;
    }

    stream = fopen(basename, "w");
    if (!stream) {
        fclose(yyin); free(basename); free(module_name);
        fprintf(stderr, "Impossible de creer '%s'\n", basename);
        return EXIT_FAILURE;
    }

    tmp_body = tmpfile();
    if (!tmp_body) {
        fclose(stream); fclose(yyin); free(basename); free(module_name);
        fprintf(stderr, "Impossible de creer le fichier temporaire\n");
        return EXIT_FAILURE;
    }

    table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);

    yyparse();

    g_hash_table_destroy(table);
    fclose(tmp_body);
    fclose(stream);
    fclose(yyin);
    free(basename);
    free(module_name);

    return EXIT_SUCCESS;
}
