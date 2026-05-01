/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "facile.y"

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


#line 107 "/home/nfall02/Téléchargements/facile/build/facile.y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "facile.y.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_NUMBER = 3,                 /* "number"  */
  YYSYMBOL_TOK_IDENTIFIER = 4,             /* "identifier"  */
  YYSYMBOL_TOK_IF = 5,                     /* "if"  */
  YYSYMBOL_TOK_THEN = 6,                   /* "then"  */
  YYSYMBOL_TOK_ELSE = 7,                   /* "else"  */
  YYSYMBOL_TOK_ELSEIF = 8,                 /* "elseif"  */
  YYSYMBOL_TOK_END = 9,                    /* "end"  */
  YYSYMBOL_TOK_ENDIF = 10,                 /* "endif"  */
  YYSYMBOL_TOK_WHILE = 11,                 /* "while"  */
  YYSYMBOL_TOK_DO = 12,                    /* "do"  */
  YYSYMBOL_TOK_ENDWHILE = 13,              /* "endwhile"  */
  YYSYMBOL_TOK_BREAK = 14,                 /* "break"  */
  YYSYMBOL_TOK_CONTINUE = 15,              /* "continue"  */
  YYSYMBOL_TOK_READ = 16,                  /* "read"  */
  YYSYMBOL_TOK_PRINT = 17,                 /* "print"  */
  YYSYMBOL_TOK_TRUE = 18,                  /* "true"  */
  YYSYMBOL_TOK_FALSE = 19,                 /* "false"  */
  YYSYMBOL_TOK_SEMI_COLON = 20,            /* ";"  */
  YYSYMBOL_TOK_AFFECTATION = 21,           /* ":="  */
  YYSYMBOL_TOK_GEQ = 22,                   /* ">="  */
  YYSYMBOL_TOK_LEQ = 23,                   /* "<="  */
  YYSYMBOL_TOK_GT = 24,                    /* ">"  */
  YYSYMBOL_TOK_LT = 25,                    /* "<"  */
  YYSYMBOL_TOK_EQ = 26,                    /* "="  */
  YYSYMBOL_TOK_NEQ = 27,                   /* "#"  */
  YYSYMBOL_TOK_OPEN_PAR = 28,              /* "("  */
  YYSYMBOL_TOK_CLOSE_PAR = 29,             /* ")"  */
  YYSYMBOL_TOK_ADD = 30,                   /* TOK_ADD  */
  YYSYMBOL_31_ = 31,                       /* "+"  */
  YYSYMBOL_TOK_SUB = 32,                   /* TOK_SUB  */
  YYSYMBOL_33_ = 33,                       /* "-"  */
  YYSYMBOL_TOK_MUL = 34,                   /* TOK_MUL  */
  YYSYMBOL_35_ = 35,                       /* "*"  */
  YYSYMBOL_TOK_DIV = 36,                   /* TOK_DIV  */
  YYSYMBOL_37_ = 37,                       /* "/"  */
  YYSYMBOL_TOK_OR = 38,                    /* TOK_OR  */
  YYSYMBOL_39_or_ = 39,                    /* "or"  */
  YYSYMBOL_TOK_AND = 40,                   /* TOK_AND  */
  YYSYMBOL_41_and_ = 41,                   /* "and"  */
  YYSYMBOL_TOK_NOT = 42,                   /* TOK_NOT  */
  YYSYMBOL_43_not_ = 43,                   /* "not"  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_code = 46,                      /* code  */
  YYSYMBOL_instruction = 47,               /* instruction  */
  YYSYMBOL_affectation = 48,               /* affectation  */
  YYSYMBOL_read = 49,                      /* read  */
  YYSYMBOL_print = 50,                     /* print  */
  YYSYMBOL_if_instr = 51,                  /* if_instr  */
  YYSYMBOL_elseif_list = 52,               /* elseif_list  */
  YYSYMBOL_else_part = 53,                 /* else_part  */
  YYSYMBOL_while_instr = 54,               /* while_instr  */
  YYSYMBOL_code_while = 55,                /* code_while  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_boolean = 57,                   /* boolean  */
  YYSYMBOL_identifier = 58,                /* identifier  */
  YYSYMBOL_number = 59                     /* number  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   139

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  85

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   138,   145,   150,   151,   152,   153,   154,
     155,   159,   169,   178,   186,   194,   203,   215,   225,   231,
     237,   243,   250,   259,   266,   272,   273,   275,   282,   289,
     296,   303,   310,   315,   320,   327,   334,   341,   348,   355,
     362,   368,   375,   382,   389,   404
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"number\"",
  "\"identifier\"", "\"if\"", "\"then\"", "\"else\"", "\"elseif\"",
  "\"end\"", "\"endif\"", "\"while\"", "\"do\"", "\"endwhile\"",
  "\"break\"", "\"continue\"", "\"read\"", "\"print\"", "\"true\"",
  "\"false\"", "\";\"", "\":=\"", "\">=\"", "\"<=\"", "\">\"", "\"<\"",
  "\"=\"", "\"#\"", "\"(\"", "\")\"", "TOK_ADD", "\"+\"", "TOK_SUB",
  "\"-\"", "TOK_MUL", "\"*\"", "TOK_DIV", "\"/\"", "TOK_OR", "\"or\"",
  "TOK_AND", "\"and\"", "TOK_NOT", "\"not\"", "$accept", "program", "code",
  "instruction", "affectation", "read", "print", "if_instr", "elseif_list",
  "else_part", "while_instr", "code_while", "expression", "boolean",
  "identifier", "number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -38,     5,   114,   -38,   -38,     0,     0,   -11,    -6,    17,
      23,   -38,   -38,   -38,   -38,   -38,   -38,     3,   -38,   -38,
     -38,     0,     0,    76,     9,   -38,   -38,    10,   -38,   -38,
      33,    23,    25,    23,    61,    29,   -38,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,   -38,     0,     0,
     -38,   -38,   103,   -38,    44,   -38,   -38,    90,    90,    90,
      90,    90,    90,    39,   -28,    20,   -38,   114,    22,   -38,
     100,   -38,     4,   -38,   -38,   -38,   -38,     0,    31,   114,
      14,   -38,   -38,   -38,   114
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,    44,     0,     0,     0,     0,     0,
       0,     3,     5,     6,     7,     8,     9,     0,    45,    32,
      33,     0,     0,     0,     0,    25,    26,     0,    10,    11,
       0,     0,     0,     0,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
      24,    13,     0,    14,     0,    31,    43,    34,    35,    36,
      37,    38,    39,    27,    28,    29,    30,    18,    42,    41,
       0,    12,    20,    21,    22,    23,     4,     0,     0,    19,
       0,    15,    16,     4,    17
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -37,   -10,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,    -8,    -5,    -2,   -38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    11,    12,    13,    14,    15,    72,    78,
      16,    70,    23,    24,    25,    26
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    27,    32,    18,     4,     3,    45,    30,    46,    28,
      67,    76,    77,    34,    29,    47,    35,    36,    19,    20,
      83,     4,    50,    52,    33,    54,    18,     4,    21,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    79,
      81,    82,    22,    68,    69,    53,    84,    48,    48,    49,
      49,    31,    48,    51,    49,    43,    46,    44,    56,    45,
      75,    46,    49,     0,    71,    17,     0,    48,    17,    49,
       0,    44,    80,    45,    43,    46,    44,    17,    45,     0,
      46,     0,    17,    37,    38,    39,    40,    41,    42,     0,
      55,    43,     0,    44,     0,    45,     0,    46,    37,    38,
      39,    40,    41,    42,     4,     5,    43,     0,    44,    73,
      45,     6,    46,    74,     7,     8,     9,    10,     4,     5,
      43,     0,    44,     0,    45,     6,    46,     0,     7,     8,
       9,    10,    55,    43,     0,    44,     0,    45,     0,    46
};

static const yytype_int8 yycheck[] =
{
       2,     6,    10,     3,     4,     0,    34,     9,    36,    20,
      47,     7,     8,    21,    20,     6,    21,    22,    18,    19,
       6,     4,    12,    31,    21,    33,     3,     4,    28,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    76,
       9,    10,    42,    48,    49,    20,    83,    38,    38,    40,
      40,    28,    38,    20,    40,    30,    36,    32,    29,    34,
      70,    36,    40,    -1,    20,    67,    -1,    38,    70,    40,
      -1,    32,    77,    34,    30,    36,    32,    79,    34,    -1,
      36,    -1,    84,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    -1,    32,    -1,    34,    -1,    36,    22,    23,
      24,    25,    26,    27,     4,     5,    30,    -1,    32,     9,
      34,    11,    36,    13,    14,    15,    16,    17,     4,     5,
      30,    -1,    32,    -1,    34,    11,    36,    -1,    14,    15,
      16,    17,    29,    30,    -1,    32,    -1,    34,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,    46,     0,     4,     5,    11,    14,    15,    16,
      17,    47,    48,    49,    50,    51,    54,    58,     3,    18,
      19,    28,    42,    56,    57,    58,    59,    57,    20,    20,
      58,    28,    56,    21,    56,    57,    57,    22,    23,    24,
      25,    26,    27,    30,    32,    34,    36,     6,    38,    40,
      12,    20,    56,    20,    56,    29,    29,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    46,    57,    57,
      55,    20,    52,     9,    13,    47,     7,     8,    53,    46,
      57,     9,    10,     6,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    49,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    58,    59
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       2,     2,     4,     3,     3,     7,     7,     5,     0,     2,
       0,     5,     5,     2,     0,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: code  */
#line 103 "facile.y"
    {
        guint nb_vars;
        guint i;
        char copy_buf[4096];
        size_t nread;

        produce_code((yyvsp[0].node));

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
#line 1517 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 3: /* code: code instruction  */
#line 139 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("code"));
        g_node_append((yyval.node), (yyvsp[-1].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1527 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 4: /* code: %empty  */
#line 145 "facile.y"
    {
        (yyval.node) = g_node_new(strdup(""));
    }
#line 1535 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 10: /* instruction: "break" ";"  */
#line 156 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("break"));
    }
#line 1543 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 11: /* instruction: "continue" ";"  */
#line 160 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("continue"));
    }
#line 1551 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 12: /* affectation: identifier ":=" expression ";"  */
#line 170 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("affectation"));
        g_node_append((yyval.node), (yyvsp[-3].node));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1561 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 13: /* read: "read" identifier ";"  */
#line 179 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("read"));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1570 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 14: /* print: "print" expression ";"  */
#line 187 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("print"));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1579 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 15: /* if_instr: "if" boolean "then" code elseif_list else_part "end"  */
#line 195 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("if"));
        g_node_append((yyval.node), (yyvsp[-5].node));
        g_node_append((yyval.node), (yyvsp[-3].node));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1591 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 16: /* if_instr: "if" boolean "then" code elseif_list else_part "endif"  */
#line 204 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("if"));
        g_node_append((yyval.node), (yyvsp[-5].node));
        g_node_append((yyval.node), (yyvsp[-3].node));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1603 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 17: /* elseif_list: elseif_list "elseif" boolean "then" code  */
#line 216 "facile.y"
    {
        GNode *ei = g_node_new(strdup("elseif"));
        g_node_append(ei, (yyvsp[-2].node));
        g_node_append(ei, (yyvsp[0].node));
        (yyval.node) = g_node_new(strdup("elseif_list"));
        g_node_append((yyval.node), (yyvsp[-4].node));
        g_node_append((yyval.node), ei);
    }
#line 1616 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 18: /* elseif_list: %empty  */
#line 225 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("elseif_list_empty"));
    }
#line 1624 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 19: /* else_part: "else" code  */
#line 232 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("else"));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1633 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 20: /* else_part: %empty  */
#line 237 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("else_empty"));
    }
#line 1641 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 21: /* while_instr: "while" boolean "do" code_while "end"  */
#line 244 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("while"));
        g_node_append((yyval.node), (yyvsp[-3].node));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1651 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 22: /* while_instr: "while" boolean "do" code_while "endwhile"  */
#line 251 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("while"));
        g_node_append((yyval.node), (yyvsp[-3].node));
        g_node_append((yyval.node), (yyvsp[-1].node));
    }
#line 1661 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 23: /* code_while: code_while instruction  */
#line 260 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("code_while"));
        g_node_append((yyval.node), (yyvsp[-1].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1671 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 24: /* code_while: %empty  */
#line 266 "facile.y"
    {
        (yyval.node) = g_node_new(strdup(""));
    }
#line 1679 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 27: /* expression: expression TOK_ADD expression  */
#line 276 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("add"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1689 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 28: /* expression: expression TOK_SUB expression  */
#line 283 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("sub"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1699 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 29: /* expression: expression TOK_MUL expression  */
#line 290 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("mul"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1709 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 30: /* expression: expression TOK_DIV expression  */
#line 297 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("div"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1719 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 31: /* expression: "(" expression ")"  */
#line 304 "facile.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1727 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 32: /* boolean: "true"  */
#line 311 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("true"));
    }
#line 1735 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 33: /* boolean: "false"  */
#line 316 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("false"));
    }
#line 1743 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 34: /* boolean: expression ">=" expression  */
#line 321 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("geq"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1753 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 35: /* boolean: expression "<=" expression  */
#line 328 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("leq"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1763 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 36: /* boolean: expression ">" expression  */
#line 335 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("gt"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1773 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 37: /* boolean: expression "<" expression  */
#line 342 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("lt"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1783 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 38: /* boolean: expression "=" expression  */
#line 349 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("eq"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1793 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 39: /* boolean: expression "#" expression  */
#line 356 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("neq"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1803 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 40: /* boolean: TOK_NOT boolean  */
#line 363 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("not"));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1812 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 41: /* boolean: boolean TOK_AND boolean  */
#line 369 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("and"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1822 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 42: /* boolean: boolean TOK_OR boolean  */
#line 376 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("or"));
        g_node_append((yyval.node), (yyvsp[-2].node));
        g_node_append((yyval.node), (yyvsp[0].node));
    }
#line 1832 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 43: /* boolean: "(" boolean ")"  */
#line 383 "facile.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1840 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 44: /* identifier: "identifier"  */
#line 390 "facile.y"
    {
        gulong value;
        (yyval.node) = g_node_new(strdup("identifier"));
        value = (gulong) g_hash_table_lookup(table, (yyvsp[0].string));
        if (!value) {
            value = (gulong) g_hash_table_size(table) + 1;
            g_hash_table_insert(table, g_strdup((yyvsp[0].string)), (gpointer) value);
        }
        g_node_append_data((yyval.node), (gpointer) value);
        g_free((yyvsp[0].string));
    }
#line 1856 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;

  case 45: /* number: "number"  */
#line 405 "facile.y"
    {
        (yyval.node) = g_node_new(strdup("number"));
        g_node_append_data((yyval.node), (gpointer) (yyvsp[0].number));
    }
#line 1865 "/home/nfall02/Téléchargements/facile/build/facile.y.c"
    break;


#line 1869 "/home/nfall02/Téléchargements/facile/build/facile.y.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 411 "facile.y"


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
