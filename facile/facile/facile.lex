%{
#include <assert.h>
#include <string.h>
#include <glib.h>
#include "facile.y.h"
%}

%option yylineno
%option nounput
%option noinput

%%

"if"       { assert(printf("'if' found\n"));       return TOK_IF;       }
"then"     { assert(printf("'then' found\n"));     return TOK_THEN;     }
"elseif"   { assert(printf("'elseif' found\n"));   return TOK_ELSEIF;   }
"else"     { assert(printf("'else' found\n"));     return TOK_ELSE;     }
"endif"    { assert(printf("'endif' found\n"));    return TOK_ENDIF;    }
"endwhile" { assert(printf("'endwhile' found\n")); return TOK_ENDWHILE; }
"end"      { assert(printf("'end' found\n"));      return TOK_END;      }
"while"    { assert(printf("'while' found\n"));    return TOK_WHILE;    }
"do"       { assert(printf("'do' found\n"));       return TOK_DO;       }
"break"    { assert(printf("'break' found\n"));    return TOK_BREAK;    }
"continue" { assert(printf("'continue' found\n")); return TOK_CONTINUE; }
"read"     { assert(printf("'read' found\n"));     return TOK_READ;     }
"print"    { assert(printf("'print' found\n"));    return TOK_PRINT;    }
"true"     { assert(printf("'true' found\n"));     return TOK_TRUE;     }
"false"    { assert(printf("'false' found\n"));    return TOK_FALSE;    }
"not"      { assert(printf("'not' found\n"));      return TOK_NOT;      }
"and"      { assert(printf("'and' found\n"));      return TOK_AND;      }
"or"       { assert(printf("'or' found\n"));       return TOK_OR;       }

":=" { assert(printf("':=' found\n")); return TOK_AFFECTATION; }
">=" { assert(printf("'>=' found\n")); return TOK_GEQ;         }
"<=" { assert(printf("'<=' found\n")); return TOK_LEQ;         }
">"  { assert(printf("'>' found\n"));  return TOK_GT;          }
"<"  { assert(printf("'<' found\n"));  return TOK_LT;          }
"="  { assert(printf("'=' found\n"));  return TOK_EQ;          }
"#"  { assert(printf("'#' found\n"));  return TOK_NEQ;         }
"+"  { assert(printf("'+' found\n"));  return TOK_ADD;         }
"-"  { assert(printf("'-' found\n"));  return TOK_SUB;         }
"*"  { assert(printf("'*' found\n"));  return TOK_MUL;         }
"/"  { assert(printf("'/' found\n"));  return TOK_DIV;         }
"("  { assert(printf("'(' found\n"));  return TOK_OPEN_PAR;    }
")"  { assert(printf("')' found\n"));  return TOK_CLOSE_PAR;   }
";"  { assert(printf("';' found\n"));  return TOK_SEMI_COLON;  }

[a-zA-Z][a-zA-Z0-9_]* {
    assert(printf("identifier '%s(%d)' found\n", yytext, yyleng));
    yylval.string = g_strdup(yytext);
    return TOK_IDENTIFIER;
}

0|[1-9][0-9]* {
    assert(printf("number '%s(%d)' found\n", yytext, yyleng));
    sscanf(yytext, "%lu", &yylval.number);
    return TOK_NUMBER;
}

"//"[^\n]* { }

[ \t\n\r] { }

. {
    fprintf(stderr, "Line %d: unknown char '%s'\n", yylineno, yytext);
    return yytext[0];
}

%%

int yywrap(void) { return 1; }
