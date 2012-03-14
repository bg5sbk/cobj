#ifndef VM_OPCODES_H
#define VM_OPCODES_H

/* Instruction opcodes */

#define OP_PASS                     0
#define OP_ADD                      1
#define OP_SUB                      2
#define OP_MUL                      3
#define OP_DIV                      4
#define OP_MOD                      5
#define OP_SL                       6
#define OP_SR                       7
#define OP_IS_SMALLER               8
#define OP_IS_SMALLER_OR_EQUAL      9
#define OP_IS_EQUAL                 10
#define OP_IS_NOT_EQUAL             11
#define OP_ASSIGN                   12
#define OP_PRINT                    13
#define OP_JMPZ                     14
#define OP_JMP                      15
#define OP_DECLARE_FUNCTION         16
#define OP_RETURN                   17
#define OP_INIT_FCALL               18
#define OP_DO_FCALL                 19
#define OP_RECV_PARAM               20
#define OP_PASS_PARAM               21
#define OP_EXIT                     22
#define OP_TRY                      23
#define OP_THROW                    24
#define OP_CATCH                    25
#define OP_BIND_NAME                26
#define OP_TUPLE_BUILD              27
#define OP_LIST_BUILD               28
#define OP_APPEND_ELEMENT              29

#endif
