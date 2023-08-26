#include "calculator.h"

void initStack(Stack* stack) { stack->top = -1; }

int isEmpty(Stack* stack) { return stack->top == -1; }

void push(Stack* stack, double value) { stack->data[++stack->top] = value; }

double pop(Stack* stack) { return stack->data[stack->top--]; }

int isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int isLetter(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int getPrecedence(char c) {
  int result = 0;
  switch (c) {
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
    case 's':
    case 'c':
    case 't':
    case 'S':
    case 'C':
    case 'T':
    case 'l':
    case 'L':
    case 'Q':
      result = 4;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

void infixToRPN(const char* infix, char* rpn) {
  Stack stack;
  initStack(&stack);

  int infixLength = strlen(infix);
  int rpnIndex = 0;
  int isUnaryMinus = 0, isUnaryPlus = 0;
  for (int i = 0; i < infixLength; i++) {
    if (isUnaryMinus) {
      rpn[rpnIndex++] = '-';
      isUnaryMinus = 0;
    }
    if (isUnaryPlus) {
      isUnaryPlus = 0;
    }
    if (isdigit(infix[i])) {
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
    } else if (infix[i] == '-' &&
               (i == 0 || isOperator(infix[i - 1]) || infix[i - 1] == '(')) {
      isUnaryMinus = 1;
      push(&stack, infix[i]);
      push(&stack, '0');
      continue;
    } else if (infix[i] == '+' &&
               (i == 0 || isOperator(infix[i - 1]) || infix[i - 1] == '(')) {
      isUnaryPlus = 1;
      continue;
    } else if (isOperator(infix[i])) {
      while (!isEmpty(&stack) &&
             getPrecedence(infix[i]) <= getPrecedence(stack.data[stack.top]) &&
             stack.data[stack.top] != '(') {
        rpn[rpnIndex++] = pop(&stack);
        rpn[rpnIndex++] = ' ';
      }
      push(&stack, infix[i]);
    } else if (isLetter(infix[i])) {
      if ((i + 3 < infixLength) &&
          (infix[i] == 's' && infix[i + 1] == 'i' && infix[i + 2] == 'n' &&
           !isLetter(infix[i + 3]))) {
        push(&stack, 's');
        i += 2;
      } else if ((i + 2 < infixLength) &&
                 (infix[i] == 'c' && infix[i + 1] == 'o' &&
                  infix[i + 2] == 's' && !isLetter(infix[i + 3]))) {
        push(&stack, 'c');
        i += 2;
      } else if ((i + 2 < infixLength) &&
                 (infix[i] == 't' && infix[i + 1] == 'a' &&
                  infix[i + 2] == 'n' && !isLetter(infix[i + 3]))) {
        push(&stack, 't');
        i += 2;
      } else if ((i + 3 < infixLength) &&
                 (infix[i] == 'a' && infix[i + 1] == 's' &&
                  infix[i + 2] == 'i' && infix[i + 3] == 'n' &&
                  !isLetter(infix[i + 4]))) {
        push(&stack, 'S');
        i += 3;
      } else if ((i + 3 < infixLength) &&
                 (infix[i] == 'a' && infix[i + 1] == 'c' &&
                  infix[i + 2] == 'o' && infix[i + 3] == 's' &&
                  !isLetter(infix[i + 4]))) {
        push(&stack, 'C');
        i += 3;
      } else if ((i + 3 < infixLength) &&
                 (infix[i] == 'a' && infix[i + 1] == 't' &&
                  infix[i + 2] == 'a' && infix[i + 3] == 'n' &&
                  !isLetter(infix[i + 4]))) {
        push(&stack, 'T');
        i += 3;
      } else if ((i + 1 < infixLength) &&
                 (infix[i] == 'l' && infix[i + 1] == 'n' &&
                  !isLetter(infix[i + 2]))) {
        push(&stack, 'l');
        i += 1;
      } else if ((i + 2 < infixLength) &&
                 (infix[i] == 'l' && infix[i + 1] == 'o' &&
                  infix[i + 2] == 'g' && !isLetter(infix[i + 3]))) {
        push(&stack, 'L');
        i += 2;
      } else if ((i + 3 < infixLength) &&
                 (infix[i] == 's' && infix[i + 1] == 'q' &&
                  infix[i + 2] == 'r' && infix[i + 3] == 't' &&
                  !isLetter(infix[i + 4]))) {
        push(&stack, 'Q');
        i += 3;
      } else {
        while (!isEmpty(&stack) && getPrecedence(infix[i]) <=
                                       getPrecedence(stack.data[stack.top])) {
          rpn[rpnIndex++] = pop(&stack);
          rpn[rpnIndex++] = ' ';
        }
        push(&stack, infix[i]);
      }
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

  char* token = strtok(rpn, " ");

  while (token) {
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
      double value = strtod(token, NULL);
      push(&stack, value);
    } else if (isOperator(token[0])) {
      double operand2 = pop(&stack);
      double operand1 = pop(&stack);
      double result = 0.0;

      switch (token[0]) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          if (strlen(token) > 1) {
            push(&stack, -operand2);
            continue;
          } else {
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
    } else if (isLetter(token[0])) {
      double operand = pop(&stack);
      double result = 0.0;

      switch (token[0]) {
        case 's':
          result = sin(operand);
          break;
        case 'c':
          result = cos(operand);
          break;
        case 't':
          result = tan(operand);
          break;
        case 'S':
          result = asin(operand);
          break;
        case 'C':
          result = acos(operand);
          break;
        case 'T':
          result = atan(operand);
          break;
        case 'l':
          result = log(operand);
          break;
        case 'L':
          result = log10(operand);
          break;
        case 'Q':
          result = sqrt(operand);
          break;
      }
      push(&stack, result);
    }
    token = strtok(NULL, " ");
  }
  return pop(&stack);
}
