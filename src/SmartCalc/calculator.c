#include "calculator.h"

// Инициализация стека
void init(Stack* stack) { stack->top = -1; }

// Проверка, является ли стек пустым
int isEmpty(Stack* stack) { return stack->top == -1; }

// Помещение элемента в стек
void push(Stack* stack, double value) {
  if (stack->top == MAX_SIZE - 1) {
    printf("Стек переполнен\n");
    exit(EXIT_FAILURE);
  }
  stack->top++;
  stack->data[stack->top] = value;
}

// Удаление элемента из стека и возврат его значения
double pop(Stack* stack) {
  // if (isEmpty(stack)) {
  //   printf("Стек пуст\n");
  //   exit(EXIT_FAILURE);
  // }
  return stack->data[stack->top--];
}

// Получение значения элемента вершины стека
double peek(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Стек пуст\n");
    exit(EXIT_FAILURE);
  }
  return stack->data[stack->top];
}

// Проверка, является ли символ оператором
int isOperator(char character) {
  return character == '+' || character == '-' || character == '*' ||
         character == '/' || character == '^' || character == '%';
}

// Проверка, является ли символ буквой
int isLetter(char character) {
  return (character >= 'a' && character <= 'z') ||
         (character >= 'A' && character <= 'Z');
}

// Проверка, является ли символ открывающей скобкой
int isOpeningBracket(char character) { return character == '('; }

// Проверка, является ли символ закрывающей скобкой
int isClosingBracket(char character) { return character == ')'; }

int isUnaryMinus(char symbol) { return symbol == '-'; }

int isUnaryPlus(char symbol) { return symbol == '+'; }

// Определение приоритета оператора
int getPriority(char oper) {
  int priority = 0;
  switch (oper) {
    case '+':
    case '-':
      priority = 1;
      break;
    case '*':
    case '/':
    case '%':
      priority = 2;
      break;
    case '^':
      priority = 3;
      break;
    default:
      priority = 0;
      break;
  }
  return priority;
}

// Определение функции с возвратом символа для выражения
char func(char* function, char* func_char) {
  if (strcmp(function, "sin") == 0) {
    *func_char = 's';
  } else if (strcmp(function, "cos") == 0) {
    *func_char = 'c';
  } else if (strcmp(function, "tan") == 0) {
    *func_char = 't';
  } else if (strcmp(function, "asin") == 0) {
    *func_char = 'S';
  } else if (strcmp(function, "acos") == 0) {
    *func_char = 'C';
  } else if (strcmp(function, "atan") == 0) {
    *func_char = 'T';
  } else if (strcmp(function, "ln") == 0) {
    *func_char = 'l';
  } else if (strcmp(function, "log") == 0) {
    *func_char = 'L';
  } else if (strcmp(function, "sqrt") == 0) {
    *func_char = 'Q';
  } else {
    printf("Некорректная функция\n");
    exit(EXIT_FAILURE);
  }
  return *func_char;
}

// Вычисление значения выражения
double calculate(double operand1, double operand2, char oper) {
  double result = 0.0;
  switch (oper) {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      if (operand2 == 0) {
        printf("Деление на ноль\n");
        exit(EXIT_FAILURE);
      }
      result = operand1 / operand2;
      break;
    case '^':
      result = pow(operand1, operand2);
      break;
    case '%':
      result = fmod(operand1, operand2);
      break;
    case 's':
      result = sin(operand2);
      break;
    case 'c':
      result = cos(operand2);
      break;
    case 't':
      result = tan(operand2);
      break;
    case 'S':
      result = asin(operand2);
      break;
    case 'C':
      result = acos(operand2);
      break;
    case 'T':
      result = atan(operand2);
      break;
    case 'l':
      result = log(operand2);
      break;
    case 'L':
      result = log10(operand2);
      break;
    case 'Q':
      result = sqrt(operand2);
      break;
    default:
      printf("Некорректный оператор\n");
      exit(EXIT_FAILURE);
  }
  return result;
}

// Парсер строки и вычисление значения выражения
double evaluateExpression(char* expression) {
  Stack operandStack;
  Stack operatorStack;
  init(&operandStack);
  init(&operatorStack);
  double result = 0.0;
  int i = 0;
  int unaryMinusFlag, unaryPlusFlag = 0;  // Флаг для унарного минуса

  while (expression[i] != '\0') {
    if (expression[i] == ' ') {
      i++;
      continue;
    }
    if (isdigit(expression[i]) || expression[i] == '.') {
      char* endPtr;
      double value = strtod(&expression[i], &endPtr);
      if (unaryMinusFlag) {
        value = -1.0 * value;
        unaryMinusFlag = 0;
      }
      if (unaryPlusFlag) {
        value = 1.0 * value;
        unaryPlusFlag = 0;
      }
      int numLength = endPtr - &expression[i];
      i += numLength;
      push(&operandStack, value);
    } else if (isLetter(expression[i])) {
      char function[MAX_SIZE];
      int j = 0;
      while (isLetter(expression[i])) {
        function[j++] = expression[i++];
      }
      function[j] = '\0';
      char func_char = func(function, &func_char);
      push(&operatorStack, func_char);
    }
    // Если символ - открывающая скобка или унарный минус, помещаем его в стек
    // операторов
    else if (isOpeningBracket(expression[i]) || isUnaryMinus(expression[i]) ||
             isUnaryPlus(expression[i])) {
      if (isUnaryMinus(expression[i]) &&
          (isOperator(expression[i - 1]) || i == 0)) {
        push(&operatorStack, '-');
      } else if (isUnaryPlus(expression[i]) &&
                 (isOperator(expression[i - 1]) || i == 0)) {
        push(&operatorStack, '+');
      } else {
        push(&operatorStack, expression[i]);
      }
      i++;

    } else if (isClosingBracket(expression[i])) {
      while (!isOpeningBracket(peek(&operatorStack))) {
        double operand2 = pop(&operandStack);
        double operand1 = pop(&operandStack);
        char oper = pop(&operatorStack);
        result = calculate(operand1, operand2, oper);
        push(&operandStack, result);
      }
      pop(&operatorStack);  // Удаляем открывающую скобку из стека операторов
      i++;
    } else if (isOperator(expression[i])) {
      while (!isEmpty(&operatorStack) &&
             !isOpeningBracket(peek(&operatorStack)) &&
             getPriority(expression[i]) <= getPriority(peek(&operatorStack))) {
        double operand2 = pop(&operandStack);
        double operand1 = pop(&operandStack);
        char oper = pop(&operatorStack);
        result = calculate(operand1, operand2, oper);
        push(&operandStack, result);
      }
      push(&operatorStack, expression[i]);
      i++;
    } else {
      printf("Некорректный символ\n");
      exit(EXIT_FAILURE);
    }
  }
  while (!isEmpty(&operatorStack)) {  // Вычисление оставшихся операторов
    double operand2 = pop(&operandStack);
    double operand1 = pop(&operandStack);
    char oper = pop(&operatorStack);
    result = calculate(operand1, operand2, oper);
    push(&operandStack, result);
    while (!isEmpty(&operatorStack) &&
           !isOpeningBracket(peek(&operatorStack))) {
      double newOperand = calculate(operand1, operand2, pop(&operatorStack));
      push(&operandStack, newOperand);
    }
  }
  return result;
}

int main() {
  // char expression[MAX_SIZE];
  char expression[MAX_SIZE] = "9/4-2";
  // printf("Введите выражение: ");
  // fgets(expression, MAX_SIZE, stdin);
  expression[strcspn(expression, "\n")] = '\0';
  double result = evaluateExpression(expression);
  printf("Результат: %lf\n", result);
  return 0;
}
