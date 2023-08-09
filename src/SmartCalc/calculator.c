#include "calculator.h"

// Функция для проверки, является ли символ оператором
int isOperator(char c) {
  int result = 0;
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' ||
      c == 's' || c == 'c' || c == 't' || c == 'C' || c == 'S' || c == 'T' ||
      c == 'l' || c == 'L' || c == 'Q') {
    result = 1;
  }
  return result;
}

// Функция для проверки, является ли символ числом
int isOperand(char c) {
  int result = 0;
  if ((c >= '0' && c <= '9') || c == '.') {
    result = 1;
  }
  return result;
}

// Функция для определения приоритета оператора
int getPriority(char oper) {
  int result = 0;
  if (oper == 's' || oper == 'c' || oper == 't' || oper == 'C' || oper == 'S' ||
      oper == 'T' || oper == 'l' || oper == 'L' || oper == 'Q') {
    result = 3;  // Высокий приоритет
  } else if (oper == '*' || oper == '/' || oper == '%' || oper == '^') {
    result = 2;  // Средний приоритет
  } else if (oper == '+' || oper == '-') {
    result = 1;  // Низкий приоритет
  } else {
    result = 0;  // Приоритет 0 для скобок
  }
  return result;
}

// Функция для выполнения операций над числами
double processOperator(double operand1, double operand2, char oper) {
  double result = 0;
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
    case 'C':
      result = acos(operand2);
      break;
    case 'S':
      result = asin(operand2);
      break;
    case 'T':
      result = atan(operand1);
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
      result = 0;
      break;
  }
  return result;
}

// Функция для вычисления значения выражения
double calculateExpression(const char *expression) {
  double operand_stack[255];  // Стек для чисел
  char operator_stack[255];   // Стек для операторов
  int operand_top = -1, operator_top = -1;
  int unary = 0;  // Флаг для унарного оператора
  int length_expression = strlen(expression);

  for (int i = 0; i < length_expression; i++) {
    char current_char = expression[i];

    if (isOperand(current_char)) {
      operand_stack[++operand_top] = atof(&expression[i]);
      while (isOperand(expression[++i]))
        ;
      i--;  // Возвращаемся назад на символ, который не является числом

      if (unary) {
        operand_stack[operand_top] = unary == '-' ? -operand_stack[operand_top]
                                                  : operand_stack[operand_top];
        unary = 0;  // Сбрасываем флаг унарного оператора
      }
    } else if (isOperator(current_char)) {
      if ((current_char == '-' || current_char == '+') &&
          (i == 0 || expression[i - 1] == '(' ||
           isOperator(expression[i - 1]))) {
        unary = current_char;
        continue;
      }

      if (operator_top == -1) {
        operator_stack[++operator_top] = current_char;
      } else if (getPriority(current_char) >
                 getPriority(operator_stack[operator_top])) {
        operator_stack[++operator_top] = current_char;
      } else {
        while (operator_top != -1 &&
               getPriority(current_char) <=
                   getPriority(operator_stack[operator_top])) {
          double operand2 = operand_stack[operand_top--];
          double operand1 = operand_stack[operand_top--];
          char oper = operator_stack[operator_top--];

          double result = processOperator(operand1, operand2, oper);

          operand_stack[++operand_top] = result;
        }

        operator_stack[++operator_top] = current_char;
      }
    } else if (current_char == '(') {
      operator_stack[++operator_top] = current_char;
    } else if (current_char == ')') {
      while (operator_stack[operator_top] != '(') {
        double operand2 = operand_stack[operand_top--];
        double operand1 = operand_stack[operand_top--];
        char oper = operator_stack[operator_top--];

        double result = processOperator(operand1, operand2, oper);

        operand_stack[++operand_top] = result;
      }
      operator_top--;
    }
  }

  while (operator_top != -1) {
    double operand2 = operand_stack[operand_top--];
    double operand1 = operand_stack[operand_top--];
    char oper = operator_stack[operator_top--];

    double result = processOperator(operand1, operand2, oper);

    operand_stack[++operand_top] = result;
  }

  return operand_stack[operand_top];
}

int main() {
  char expression[256];

  printf("Выражение: ");
  fgets(expression, sizeof(expression), stdin);

  // Удаляем символ новой строки из ввода
  if (expression[strlen(expression) - 1] == '\n') {
    expression[strlen(expression) - 1] = '\0';
  }

  float result = calculateExpression(expression);

  printf("Result: %.7f\n", result);

  return 0;
}
