#include "calculator.h"

double calculate_operand(const char* expression, size_t* index) {
  double operand = atof(&expression[*index]);
  while (isdigit(expression[*index]) || expression[*index] == '.') {
    (*index)++;
  }
  (*index)--;  // Возвращаемся на символ, который не является числом
  return operand;
}

double perform_operation(double operand1, double operand2, char oper) {
    double result = 0.0;
      switch (oper) {
        case '+':
          result = operand1 + operand2;
        case '-':
          result = operand1 - operand2;
        case '*':
          result = operand1 * operand2;
        case '/':
          result = operand1 / operand2;
        case '^':
          result = pow(operand1, operand2);
        case '%':
          result = fmod(operand1, operand2);
      }
  return result;
}

int get_priority(char oper) {
    int result = 0;
  if (oper == '+' || oper == '-') {
    result = 1;
  } else if (oper == '*' || oper == '/' || oper == '%') {
    result = 2;
  } else if (oper == '^') {
    result = 3;
  } else {
    result = 0;
  }
  return result;
}

int is_operator(char ch) {
  return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
         ch == '%';
}

double calculate_expression(const char* expression) {
  double operand_stack[255];  // Стек для чисел
  char operator_stack[255];   // Стек для операторов
  int operand_top = -1;
  int operator_top = -1;
  int unary_minus = 0;  // Флаг для унарного минуса
  int unary_plus = 0;   // Флаг для унарного плюса

  for (size_t i = 0; i < strlen(expression); i++) {
    char current_char = expression[i];
    if (isdigit(current_char)) {
      operand_top++;
      operand_stack[operand_top] = calculate_operand(expression, &i);
      if (unary_minus) {
        operand_stack[operand_top] = -operand_stack[operand_top];
        unary_minus = 0;  // Сбрасываем флаг унарного минуса
      }
      if (unary_plus) {
        unary_plus = 0;  // Сбрасываем флаг унарного плюса
      }
    } else if (is_operator(current_char)) {
      // Обработка для унарного минуса и плюса
      if ((current_char == '-' || current_char == '+')) {
        if (i == 0 || (i > 0 && is_operator(expression[i - 1]))) {
          if (current_char == '-') {
            unary_minus = 1;
          } else if (current_char == '+') {
            unary_plus = 1;
          }
          continue;
        }
      }
      if (operator_top == -1) {
        operator_top++;
        operator_stack[operator_top] = current_char;
      } else if (get_priority(current_char) >
                 get_priority(operator_stack[operator_top])) {
        operator_top++;
        operator_stack[operator_top] = current_char;
      } else {
        while (operator_top != -1 &&
               get_priority(current_char) <=
                   get_priority(operator_stack[operator_top])) {
          double operand2 = operand_stack[operand_top];
          operand_top--;
          double operand1 = operand_stack[operand_top];
          operand_top--;
          char oper = operator_stack[operator_top];
          operator_top--;

          double result = perform_operation(operand1, operand2, oper);

          operand_top++;
          operand_stack[operand_top] = result;
        }

        operator_top++;
        operator_stack[operator_top] = current_char;
      }
    } else if (current_char == '(') {
      operator_top++;
      operator_stack[operator_top] = current_char;
    } else if (current_char == ')') {
      while (operator_stack[operator_top] != '(') {
        double operand2 = operand_stack[operand_top];
        operand_top--;
        double operand1 = operand_stack[operand_top];
        operand_top--;
        char oper = operator_stack[operator_top];
        operator_top--;

        double result = perform_operation(operand1, operand2, oper);

        operand_top++;
        operand_stack[operand_top] = result;
      }

      // Удаляем открывающую скобку из стека операторов
      operator_top--;

    } else if (current_char == 's' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'i' && expression[i + 2] == 'n') {
      i += 6;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = sin(arg);
    } else if (current_char == 'c' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'o' && expression[i + 2] == 's') {
      i += 6;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = cos(arg);
    } else if (current_char == 't' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'a' && expression[i + 2] == 'n') {
      i += 6;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = tan(arg);
    } else if (current_char == 'a' && i < strlen(expression) - 2 &&
               expression[i + 1] == 's' && expression[i + 2] == 'i' &&
               expression[i + 3] == 'n') {
      i += 7;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = asin(arg);
    } else if (current_char == 'a' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'c' && expression[i + 2] == 'o' &&
               expression[i + 3] == 's') {
      i += 7;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = acos(arg);
    } else if (current_char == 'a' && i < strlen(expression) - 2 &&
               expression[i + 1] == 't' && expression[i + 2] == 'a' &&
               expression[i + 3] == 'n') {
      i += 7;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = atan(arg);
    } else if (current_char == 'l' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'n') {
      i += 5;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = log(arg);
    } else if (current_char == 'l' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'o' && expression[i + 2] == 'g') {
      i += 6;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = log10(arg);
    } else if (current_char == 's' && i < strlen(expression) - 2 &&
               expression[i + 1] == 'q' && expression[i + 2] == 'r' &&
               expression[i + 3] == 't') {
      i += 7;
      double arg = calculate_operand(expression, &i);
      operand_top++;
      operand_stack[operand_top] = sqrt(arg);
    }
  }

  while (operator_top != -1) {
    double operand2 = operand_stack[operand_top];
    operand_top--;
    double operand1 = operand_stack[operand_top];
    operand_top--;
    char oper = operator_stack[operator_top];
    operator_top--;

    double result = perform_operation(operand1, operand2, oper);

    operand_top++;
    operand_stack[operand_top] = result;
  }

  return operand_stack[operand_top];
}
