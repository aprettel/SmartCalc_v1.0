#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255

// Стек для хранения операторов
struct Stack {
  int top;
  double items[MAX_SIZE];
};

void push(struct Stack* stack, double item);
double pop(struct Stack* stack);
int isOperator(char ch);
int isDigit(char ch);
int isOperand(char ch);
int getPrecedence(char op);
double processOperator(char op, double rightOperand, double leftOperand);
char* convertToRPN(const char* expression);
double evaluateRPN(const char* rpn);

#endif  // CALCULATOR_H
