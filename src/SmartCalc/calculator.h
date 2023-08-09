#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isOperator(char c);
int isOperand(char c);
int getPriority(char oper);
double processOperator(double operand1, double operand2, char oper);
double calculateExpression(const char* expression);

#endif  // CALCULATOR_H
