#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 255

// Структура стека
typedef struct {
  double data[MAX_SIZE];
  int top;
} Stack;

void init(Stack* stack);
int isEmpty(Stack* stack);
void push(Stack* stack, double value);
double pop(Stack* stack);
double peek(Stack* stack);
int isOperator(char character);
int isLetter(char character);
int isOpeningBracket(char character);
int isClosingBracket(char character);
int isUnaryMinus(char symbol);
int isUnaryPlus(char symbol);
int getPriority(char oper);
char func(char* function, char* func_char);
double calculate(double operand1, double operand2, char oper);
double evaluateExpression(char* expression);
