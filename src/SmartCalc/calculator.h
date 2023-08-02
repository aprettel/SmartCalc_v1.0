#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_operator(char c);
int is_operand(char c);
int get_priority(char oper);
double check_operation(char* tmp_expression, double operand1, double operand2,
                       char oper);
double binary_operation(double operand1, double operand2, char oper);
double unary_operation(double operand1, char oper);
double calculate_expression(const char* expression);

#endif  // CALCULATOR_H
