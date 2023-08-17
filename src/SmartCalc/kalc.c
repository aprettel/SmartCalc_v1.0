#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 100

typedef struct {
    double data[MAX_EXPRESSION_LENGTH];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_EXPRESSION_LENGTH - 1;
}

void push(Stack* stack, double value) {
    if (isFull(stack)) {
        printf("Стек переполнен\n");
        exit(1);
    }
    
    stack->data[++stack->top] = value;
}

double pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Стэк пуст\n");
        exit(1);
    }
    
    return stack->data[stack->top--];
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int getPrecedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void infixToRPN(char* infix, char* rpn) {
    Stack stack;
    initStack(&stack);
    
    int infixLength = strlen(infix);
    int rpnIndex = 0;
    
    for (int i = 0; i < infixLength; i++) {
        if (isdigit(infix[i]) || (infix[i] == '-' && (i == 0 || isOperator(infix[i-1]) || infix[i-1] == '(') && isdigit(infix[i+1]))) { // учитываем отрицательные числа
            while (isdigit(infix[i]) || infix[i] == '.') {
                rpn[rpnIndex++] = infix[i++];
            }
            rpn[rpnIndex++] = ' ';
            i--;
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
                rpn[rpnIndex++] = pop(&stack);
                rpn[rpnIndex++] = ' ';
            }
            if (!isEmpty(&stack) && stack.data[stack.top] == '(') {
                pop(&stack);
            }
        } else if (isOperator(infix[i])) {
            while (!isEmpty(&stack) && getPrecedence(infix[i]) <= getPrecedence(stack.data[stack.top]) && stack.data[stack.top] != '(') {
                rpn[rpnIndex++] = pop(&stack);
                rpn[rpnIndex++] = ' ';
            }
            push(&stack, infix[i]);
        }
    }
    
    while (!isEmpty(&stack)) {
        rpn[rpnIndex++] = pop(&stack);
        rpn[rpnIndex++] = ' ';
    }
    
    rpn[rpnIndex] = '\0';
}

double calculateRPN(char* rpn) {
    Stack stack;
    initStack(&stack);
    
    int rpnLength = strlen(rpn);
    
    for (int i = 0; i < rpnLength; i++) {
        if (isdigit(rpn[i]) || (rpn[i] == '-' && isdigit(rpn[i+1]))) { // учитываем отрицательные числа
            double value = atof(&rpn[i]);
            push(&stack, value);
            while (isdigit(rpn[i+1]) || rpn[i+1] == '.') {
                i++;
            }
        } else if (rpn[i] == ' ') {
            // игнорируем пробелы
        } else if (isOperator(rpn[i])) {
            double operand2 = pop(&stack);
            double operand1 = 0.0;
            if (rpn[i] != '+' && rpn[i] != '-' && rpn[i] != '%') { // для операций с одним операндом берем только один операнд
                operand1 = pop(&stack);
            }
            
            double result = 0.0;
            switch (rpn[i]) {
                case '+':
                    result = pop(&stack) + operand2;
                    break;
                case '-':
                    if (isEmpty(&stack)) { // унарный минус
                        result = -operand2;
                    } else {
                        operand1 = pop(&stack);
                        result = operand1 - operand2;
                    }
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
                case '%':
                    result = fmod(operand1, operand2);
                    break;
            }
            
            push(&stack, result);
        }
    }
    
    return pop(&stack);
} 

int main() {
    char infix[MAX_EXPRESSION_LENGTH];
    char rpn[MAX_EXPRESSION_LENGTH];
    
    printf("введи выражение: ");
    fgets(infix, MAX_EXPRESSION_LENGTH, stdin);
    infix[strlen(infix)-1] = '\0'; // удаляем символ перевода строки
    
    infixToRPN(infix, rpn);
    
    printf("перевод в RPN: %s\n", rpn);
    
    double result = calculateRPN(rpn);
    
    printf("результат: %lf\n", result);
    
    return 0;
} 
