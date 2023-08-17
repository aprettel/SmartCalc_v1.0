#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 255

typedef struct {
  double data[MAX_EXPRESSION_LENGTH];
  int top;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, double value);
double pop(Stack* stack);
int isOperator(char c);
int isLetter(char c);
int getPrecedence(char c);
void infixToRPN(const char* infix, char* rpn);
double calculateRPN(char* rpn);

#endif  // CALCULATOR_H
