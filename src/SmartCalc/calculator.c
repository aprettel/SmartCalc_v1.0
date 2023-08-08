#include "calculator.h"

void push(struct Stack* stack, double item) {
  stack->items[++stack->top] = item;
}

double pop(struct Stack* stack) { return stack->items[stack->top--]; }

int isOperator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
         ch == '%';
}

int isDigit(char ch) { return (ch >= '0' && ch <= '9') || ch == '.'; }

int isOperand(char ch) {
  return isOperator(ch) || isDigit(ch) || ch == '(' || ch == ')';
}

int getPrecedence(char op) {
  int result = 0;
  switch (op) {
    case '+':
    case '-':
      result = 1;
      break;
    case '*':
    case '/':
    case '%':
      result = 2;
      break;
    case '^':
      result = 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

double processOperator(char op, double rightOperand, double leftOperand) {
  double result = 0.0;
  switch (op) {
    case '+':
      result = leftOperand + rightOperand;
      break;
    case '-':
      result = leftOperand - rightOperand;
      break;
    case '*':
      result = leftOperand * rightOperand;
      break;
    case '/':
      result = leftOperand / rightOperand;
      break;
    case '^':
      result = pow(leftOperand, rightOperand);
      break;
    case '%':
      result = fmod(leftOperand, rightOperand);
      break;
  }

  return result;
}

double evaluateRPN(const char* rpn) {
  struct Stack stack;
  stack.top = -1;

  int len = strlen(rpn);

  char* endPtr;

  for (int i = 0; i < len; i++) {
    char ch = rpn[i];

    if (isDigit(ch)) {
      double operand = strtod(&rpn[i], &endPtr);
      push(&stack, operand);
      i += endPtr - &rpn[i] - 1;
    } else if (isOperator(ch)) {
      double rightOperand = pop(&stack);
      double leftOperand = pop(&stack);
      double result = processOperator(ch, rightOperand, leftOperand);
      push(&stack, result);
    }
  }

  return stack.items[stack.top];
}

char* convertToRPN(const char* expression, char* output) {
  struct Stack operatorStack;
  operatorStack.top = -1;

  int len = strlen(expression);
  int j = 0;

  for (int i = 0; i < len; i++) {
    char ch = expression[i];

    if (isDigit(ch)) {
      while (i < len && (isDigit(expression[i]) || expression[i] == '.')) {
        output[j++] = expression[i++];
      }
      output[j++] = ' ';
      i--;
    } else if (isOperator(ch)) {
      while (operatorStack.top != -1 &&
             isOperator(operatorStack.items[operatorStack.top]) &&
             getPrecedence(ch) <=
                 getPrecedence(operatorStack.items[operatorStack.top])) {
        output[j++] = pop(&operatorStack);
        output[j++] = ' ';
      }
      push(&operatorStack, ch);
    } else if (ch == '(') {
      push(&operatorStack, '(');
    } else if (ch == ')') {
      while (operatorStack.top != -1 &&
             operatorStack.items[operatorStack.top] != '(') {
        output[j++] = pop(&operatorStack);
        output[j++] = ' ';
      }
      pop(&operatorStack);  // Игнорируем '('
    }
  }

  while (operatorStack.top != -1) {
    output[j++] = pop(&operatorStack);
    output[j++] = ' ';
  }

  output[j] = '\0';

  return output;
}

// int main() {
//     char expression[100];
//     printf("Введите выражение в инфиксной нотации: ");
//     fgets(expression, sizeof(expression), stdin);
//     char rpn[255];
//     convertToRPN(expression, rpn);
//     double result = evaluateRPN(rpn);

//    printf("Результат: %.2f\n", result);

//    // free(rpn);

//    return 0;
//}
