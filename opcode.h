#ifndef OPCODES_H
#define OPCODES_H

/* Instruction opcodes */

enum {
    OP_NOP,
    OP_BINARY_ADD,
    OP_BINARY_SUB,
    OP_BINARY_MUL,
    OP_BINARY_DIV,
    OP_BINARY_MOD,
    OP_BINARY_POW,
    OP_BINARY_SL,
    OP_BINARY_SR,
    OP_BINARY_SUBSCRIPT,
    OP_CMP,
    OP_UNARY_NEGATE,
    OP_UNARY_INVERT,
    OP_UNARY_NOT,
    OP_STORE_NAME,
    OP_JMPZ,
    OP_JMP,
    OP_JMPX,
    OP_MAKE_FUNCTION,
    OP_MAKE_CLASS,
    OP_RETURN,
    OP_CALL_FUNCTION,
    OP_SETUP_TRY,
    OP_THROW,
    OP_LOAD_NAME,
    OP_LOAD_CONST,
    OP_BUILD_TUPLE,
    OP_BUILD_LIST,
    OP_DICT_BUILD,
    OP_DICT_ADD,
    OP_SETUP_LOOP,
    OP_POP_BLOCK,
    OP_BREAK_LOOP,
    OP_CONTINUE_LOOP,
    OP_POP_TRY,
    OP_DUP_TOP,
    OP_POP_TOP,
    OP_END_TRY,
    OP_SETUP_FINALLY,
    OP_END_FINALLY,
    OP_STORE_SUBSCRIPT,
    OP_LOAD_LOCAL,
    OP_LOAD_UPVAL,
    OP_STORE_UPVAL,
    OP_STORE_LOCAL,
    OP_GET_ITER,
    OP_FOR_ITER,
    OP_GET_ATTR,
    OP_SET_ATTR,
    OP_DEL_ATTR,
    OP_IMPORT_NAME,
    OP_IMPORT_FROM,
    OP_IMPORT_STAR,
    OP_UNPACK_SEQUENCE,
    OP_JUMP_IF_FALSE_OR_POP,
    OP_JUMP_IF_TRUE_OR_POP,
};

/* OP_CMP's opargs */

enum {
    Cmp_LT = 0,
    Cmp_LE = 1,
    Cmp_EQ = 2,
    Cmp_NE = 3,
    Cmp_GT = 4,
    Cmp_GE = 5,
    Cmp_EXC_MATCH = 6,
    Cmp_IN = 7,
    Cmp_NOT_IN = 8,
    Cmp_IS = 9,
    Cmp_IS_NOT = 10,
};

char *opcode_name(unsigned char opcode);

#endif
