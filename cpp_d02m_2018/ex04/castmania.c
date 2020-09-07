/*
** EPITECH PROJECT, 2019
** castmania.c
** File description:
** castmania file
*/

#include <stdio.h>
#include "castmania.h"

void exec_operation(instruction_type_t instruction_type , void *data)
{
    instruction_t *tmp = (instruction_t *)data;
    addition_t *add = (addition_t *)tmp->operation;
    division_t *div = (division_t *)tmp->operation;
    integer_op_t *int_op;
    decimale_op_t *dec_op;

    if (instruction_type == ADD_OPERATION) {
        exec_add(tmp->operation);
        if (tmp->output_type == VERBOSE)
            printf("%d\n", add->add_op.res);
    } else if (instruction_type == DIV_OPERATION) {
        if (div->div_type  == INTEGER)
            int_op = (integer_op_t *)div->div_op;
        else if (div->div_type == DECIMALE)
            dec_op = (decimale_op_t *)div->div_op;
        exec_div(tmp->operation);
        tmp->output_type == VERBOSE && div->div_type  == INTEGER ?
        printf("%d\n", int_op->res) : printf("%f\n", dec_op->res);
    }
}

void exec_instruction(instruction_type_t instruction_type , void *data)
{
    if (instruction_type == PRINT_INT) {
        printf("%d\n", *((int *)data));
    } else if (instruction_type == PRINT_FLOAT) {
        printf("%f\n", *((float *)data));
    } else
        exec_operation(instruction_type, data);
}
