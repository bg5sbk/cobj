#ifndef CO_OPCODE_H
#define CO_OPCODE_H

/* Instruction opcodes for compiled code */

#define OP_NOP                               0
#define OP_ADD                               1
#define OP_SUB                               2
#define OP_MUL                               3
#define OP_DIV                               4
#define OP_MOD                               5
#define OP_SL                                6
#define OP_SR                                7
#define OP_CONCAT                            8
#define OP_BW_OR                             9
#define OP_BW_AND                           10
#define OP_BW_XOR                           11
#define OP_BW_NOT                           12
#define OP_BOOL_NOT                         13
#define OP_BOOL_XOR                         14
#define OP_IS_IDENTICAL                     15
#define OP_IS_NOT_IDENTICAL                 16
#define OP_IS_EQUAL                         17
#define OP_IS_NOT_EQUAL                     18
#define OP_IS_SMALLER                       19
#define OP_IS_SMALLER_OR_EQUAL              20
#define OP_CAST                             21
#define OP_QM_ASSIGN                        22
#define OP_ASSIGN_ADD                       23
#define OP_ASSIGN_SUB                       24
#define OP_ASSIGN_MUL                       25
#define OP_ASSIGN_DIV                       26
#define OP_ASSIGN_MOD                       27
#define OP_ASSIGN_SL                        28
#define OP_ASSIGN_SR                        29
#define OP_ASSIGN_CONCAT                    30
#define OP_ASSIGN_BW_OR                     31
#define OP_ASSIGN_BW_AND                    32
#define OP_ASSIGN_BW_XOR                    33
#define OP_PRE_INC                          34
#define OP_PRE_DEC                          35
#define OP_POST_INC                         36
#define OP_POST_DEC                         37
#define OP_ASSIGN                           38
#define OP_ASSIGN_REF                       39
#define OP_ECHO                             40
#define OP_PRINT                            41
#define OP_JMP                              42
#define OP_JMPZ                             43
#define OP_JMPNZ                            44
#define OP_JMPZNZ                           45
#define OP_JMPZ_EX                          46
#define OP_JMPNZ_EX                         47
#define OP_CASE                             48
#define OP_SWITCH_FREE                      49
#define OP_BRK                              50
#define OP_CONT                             51
#define OP_BOOL                             52
#define OP_INIT_STRING                      53
#define OP_ADD_CHAR                         54
#define OP_ADD_STRING                       55
#define OP_ADD_VAR                          56
#define OP_BEGIN_SILENCE                    57
#define OP_END_SILENCE                      58
#define OP_INIT_FCALL_BY_NAME               59
#define OP_DO_FCALL                         60
#define OP_DO_FCALL_BY_NAME                 61
#define OP_RETURN                           62
#define OP_RECV                             63
#define OP_RECV_INIT                        64
#define OP_SEND_VAL                         65
#define OP_SEND_VAR                         66
#define OP_SEND_REF                         67
#define OP_NEW                              68
#define OP_INIT_NS_FCALL_BY_NAME            69
#define OP_FREE                             70
#define OP_INIT_ARRAY                       71
#define OP_ADD_ARRAY_ELEMENT                72
#define OP_INCLUDE_OR_EVAL                  73
#define OP_UNSET_VAR                        74
#define OP_UNSET_DIM                        75
#define OP_UNSET_OBJ                        76
#define OP_FE_RESET                         77
#define OP_FE_FETCH                         78
#define OP_EXIT                             79
#define OP_FETCH_R                          80
#define OP_FETCH_DIM_R                      81
#define OP_FETCH_OBJ_R                      82
#define OP_FETCH_W                          83
#define OP_FETCH_DIM_W                      84
#define OP_FETCH_OBJ_W                      85
#define OP_FETCH_RW                         86
#define OP_FETCH_DIM_RW                     87
#define OP_FETCH_OBJ_RW                     88
#define OP_FETCH_IS                         89
#define OP_FETCH_DIM_IS                     90
#define OP_FETCH_OBJ_IS                     91
#define OP_FETCH_FUNC_ARG                   92
#define OP_FETCH_DIM_FUNC_ARG               93
#define OP_FETCH_OBJ_FUNC_ARG               94
#define OP_FETCH_UNSET                      95
#define OP_FETCH_DIM_UNSET                  96
#define OP_FETCH_OBJ_UNSET                  97
#define OP_FETCH_DIM_TMP_VAR                98
#define OP_FETCH_CONSTANT                   99
#define OP_GOTO                            100
#define OP_EXT_STMT                        101
#define OP_EXT_FCALL_BEGIN                 102
#define OP_EXT_FCALL_END                   103
#define OP_EXT_NOP                         104
#define OP_TICKS                           105
#define OP_SEND_VAR_NO_REF                 106
#define OP_CATCH                           107
#define OP_THROW                           108
#define OP_FETCH_CLASS                     109
#define OP_CLONE                           110
#define OP_INIT_METHOD_CALL                112
#define OP_INIT_STATIC_METHOD_CALL         113
#define OP_ISSET_ISEMPTY_VAR               114
#define OP_ISSET_ISEMPTY_DIM_OBJ           115
#define OP_PRE_INC_OBJ                     132
#define OP_PRE_DEC_OBJ                     133
#define OP_POST_INC_OBJ                    134
#define OP_POST_DEC_OBJ                    135
#define OP_ASSIGN_OBJ                      136
#define OP_INSTANCEOF                      138
#define OP_DECLARE_CLASS                   139
#define OP_DECLARE_INHERITED_CLASS         140
#define OP_DECLARE_FUNCTION                141
#define OP_RAISE_ABSTRACT_ERROR            142
#define OP_DECLARE_CONST                   143
#define OP_ADD_INTERFACE                   144
#define OP_DECLARE_INHERITED_CLASS_DELAYED 145
#define OP_VERIFY_ABSTRACT_CLASS           146
#define OP_ASSIGN_DIM                      147
#define OP_ISSET_ISEMPTY_PROP_OBJ          148
#define OP_HANDLE_EXCEPTION                149
#define OP_USER_OPCODE                     150
#define OP_U_NORMALIZE                     151
#define OP_JMP_SET                         152
#define OP_DECLARE_LAMBDA_FUNCTION         153

#endif
