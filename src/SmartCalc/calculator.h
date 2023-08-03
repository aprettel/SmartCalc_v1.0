#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calculate_operand(const char* expression, size_t* index);
double perform_operation(double operand1, double operand2, char oper);
int get_priority(char oper);
int is_operator(char ch);
double calculate_expression(const char* expression);

#endif  // CALCULATOR_H
