%{
#include "co.h"

//#define YYSTYPE Node *

%}

%pure_parser
%debug
%error-verbose
/*%expect 5*/
%union {
    Node *node;    
    NodeList *list;
}

%parse-param {struct compiler *c}

%nonassoc T_EQUAL T_NOT_EQUAL 
%token T_MOD_ASSIGN T_DIV_ASSIGN T_MUL_ASSIGN T_SUB_ASSIGN T_ADD_ASSIGN T_SR_ASSIGN T_SL_ASSIGN
%nonassoc '<' '>' T_SMALLER_OR_EQUAL T_GREATER_OR_EQUAL
%left   ','
%left   '+' '-'
%left   '*' '/' '%'
%left T_SR T_SL T_POW
%right  '['
%right  T_PRINT
%token  T_IF T_ELIF T_ELSE
%token  T_FUNC
%token  T_RETURN
%token  T_WHILE
%token  T_NEWLINES
%token  T_WHITESPACE
%token  T_COMMENT
%token  T_IGNORED
%token  T_TRY
%token  T_THROW
%token  T_CATCH
%token  T_FINALLY
%token  T_END
%token  <node> T_NONE
%token  <node> T_BOOL
%token  <node> T_NUM
%token  <node> T_FNUM
%token  <node> T_STRING
%token  <node> T_NAME

%type <node> expr
%type <list> simple_stmt
%type <list> stmt stmt_list start open_stmt_list
%type <list> expr_list non_empty_expr_list
%type <list> assoc_list non_empty_assoc_list

%% /* Context-Free Grammar (BNF) */

start: stmt_list { 
     c->xtop = $$; 
     c->xtop = node_concat(c->xtop, node_list(node_new(NODE_RETURN, NULL, NULL), NULL));
    }
;

stmt: /* state something */
        simple_stmt { $$ = $1; }
;

stmt_list:
         open_stmt_list opt_stmt_seps { $$ = $1; }
;

open_stmt_list:
        stmt { $$ = $1; }
    |   open_stmt_list stmt_seps stmt { $$ = node_concat($1, $3); }
    |   /* empty */ {}
;

stmt_sep:
        T_NEWLINES
    |   ';'
;

stmt_seps:
        stmt_sep
    |   stmt_seps stmt_sep
;

opt_stmt_seps:
        /* empty */
    |   stmt_seps
;

expr: /* express something */
        T_NAME
    |   T_STRING
    |   T_BOOL
    |   T_NONE
    |   T_NUM
    |   T_FNUM
    |    '(' expr ')' { $$ = $2; }
    |   expr '+' expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_ADD; }
    |   expr '-' expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_SUB; }
    |   expr '*' expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_MUL; }
    |   expr '/' expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_DIV; }
    |   expr '%' expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_MOD; }
    |   expr '<' expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_IS_SMALLER; }
    |   expr '>' expr { $$ = node_new(NODE_BIN, $3, $1); $$->op = OP_IS_SMALLER; }
    |   expr T_EQUAL expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_IS_EQUAL; }
    |   expr T_NOT_EQUAL expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_IS_NOT_EQUAL; }
    |   expr T_SMALLER_OR_EQUAL expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_IS_SMALLER_OR_EQUAL; }
    |   expr T_GREATER_OR_EQUAL expr { $$ = node_new(NODE_BIN, $3, $1); $$->op = OP_IS_SMALLER_OR_EQUAL; }
    |   expr T_SL expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_SL; }
    |   expr T_SR expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_SR; }
    |   expr T_POW expr { $$ = node_new(NODE_BIN, $1, $3); $$->op = OP_POW; }
    |   '[' expr_list ']' { 
            $$ = node_new(NODE_LIST_BUILD, NULL, NULL);
            $$->list = $2; 
        }
    |   '{' assoc_list '}' {
            $$ = node_new(NODE_DICT_BUILD, NULL, NULL);
            $$->list = $2;
        }
;

opt_comma:
        ',' opt_newlines
    |   /* empty */
;

opt_newlines:
        T_NEWLINES
    |   /* empty */
;

expr_list:
        non_empty_expr_list opt_comma
    |   /* empty */ {}
;

non_empty_expr_list:
        opt_newlines expr opt_newlines { 
            $$ = node_list(node_new(NODE_LIST_ADD, $2, NULL), NULL);
        }
    |   non_empty_expr_list ',' opt_newlines expr opt_newlines {
            $$ = node_append($1, node_new(NODE_LIST_ADD, $4, NULL));
        }
;

assoc_list:
        non_empty_assoc_list opt_comma
    |   /* empty */ {}
;   

non_empty_assoc_list:
        opt_newlines expr ':' expr opt_newlines { 
            $$ = node_list(node_new(NODE_DICT_ADD, $2, $4), NULL);
        }
    |   non_empty_assoc_list ',' opt_newlines expr ':' expr opt_newlines { 
            $$ = node_append($1, node_new(NODE_DICT_ADD, $4, $6));
        }
;

simple_stmt:
        T_NAME '=' expr { $$ = node_new(NODE_ASSIGN, $1, $3); $$ = node_list($$, NULL); }
    |   T_NAME T_ADD_ASSIGN expr { 
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_ADD;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_NAME T_SUB_ASSIGN expr  {
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_SUB;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_NAME T_MUL_ASSIGN expr  {
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_MUL;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_NAME T_DIV_ASSIGN expr  {
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_DIV;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_NAME T_MOD_ASSIGN expr {
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_MOD;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_NAME T_SR_ASSIGN expr {
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_SR;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_NAME T_SL_ASSIGN expr {
            Node *t;
            t = node_new(NODE_BIN, $1, $3); t->op = OP_SL;
            $$ = node_list(t, node_new(NODE_ASSIGN, $1, t), NULL);
        }
    |   T_PRINT expr { $$ = node_new(NODE_PRINT, $2, NULL); $$ = node_list($$, NULL); }
    |   expr { $$ = node_list($$, NULL); }
;

%%
