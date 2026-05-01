/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_NFALL02_T_L_CHARGEMENTS_FACILE_BUILD_FACILE_Y_H_INCLUDED
# define YY_YY_HOME_NFALL02_T_L_CHARGEMENTS_FACILE_BUILD_FACILE_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_NUMBER = 258,              /* "number"  */
    TOK_IDENTIFIER = 259,          /* "identifier"  */
    TOK_IF = 260,                  /* "if"  */
    TOK_THEN = 261,                /* "then"  */
    TOK_ELSE = 262,                /* "else"  */
    TOK_ELSEIF = 263,              /* "elseif"  */
    TOK_END = 264,                 /* "end"  */
    TOK_ENDIF = 265,               /* "endif"  */
    TOK_WHILE = 266,               /* "while"  */
    TOK_DO = 267,                  /* "do"  */
    TOK_ENDWHILE = 268,            /* "endwhile"  */
    TOK_BREAK = 269,               /* "break"  */
    TOK_CONTINUE = 270,            /* "continue"  */
    TOK_READ = 271,                /* "read"  */
    TOK_PRINT = 272,               /* "print"  */
    TOK_TRUE = 273,                /* "true"  */
    TOK_FALSE = 274,               /* "false"  */
    TOK_SEMI_COLON = 275,          /* ";"  */
    TOK_AFFECTATION = 276,         /* ":="  */
    TOK_GEQ = 277,                 /* ">="  */
    TOK_LEQ = 278,                 /* "<="  */
    TOK_GT = 279,                  /* ">"  */
    TOK_LT = 280,                  /* "<"  */
    TOK_EQ = 281,                  /* "="  */
    TOK_NEQ = 282,                 /* "#"  */
    TOK_OPEN_PAR = 283,            /* "("  */
    TOK_CLOSE_PAR = 284,           /* ")"  */
    TOK_ADD = 285,                 /* TOK_ADD  */
    TOK_SUB = 287,                 /* TOK_SUB  */
    TOK_MUL = 289,                 /* TOK_MUL  */
    TOK_DIV = 291,                 /* TOK_DIV  */
    TOK_OR = 293,                  /* TOK_OR  */
    TOK_AND = 295,                 /* TOK_AND  */
    TOK_NOT = 297                  /* TOK_NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "facile.y"

    gulong number;
    gchar *string;
    GNode *node;

#line 106 "/home/nfall02/Téléchargements/facile/build/facile.y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_HOME_NFALL02_T_L_CHARGEMENTS_FACILE_BUILD_FACILE_Y_H_INCLUDED  */
