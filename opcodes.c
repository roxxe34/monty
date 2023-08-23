#include "monty.h"

instruction_t instructions[] = {
    {"push", opcode_push},
    {"pall", opcode_pall},
    {"pint", opcode_pint},
    {"pop", opcode_pop},
    {"swap", opcode_swap},
    {"add", opcode_add},
    {"nop", opcode_nop},
    {"sub", opcode_sub},
    {"div", opcode_div},
    {"mul", opcode_mul},
    {"mod", opcode_mod},
    {"pchar", opcode_pchar},
    {"pstr", opcode_pstr},
    {"rotl", opcode_rotl},
    
    /* Add more instructions as needed */
    {NULL, NULL}
};