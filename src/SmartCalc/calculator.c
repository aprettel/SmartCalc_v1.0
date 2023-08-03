#include "calculator.h"

// Функция для проверки, является ли символ оператором
int is_operator(char c) {
  int result = 0;
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%' ||
      c == 's' || c == 'c' || c == 't' || c == 'C' || c == 'S' || c == 'T' ||
      c == 'l' || c == 'L' || c == 'Q') {
    result = 1;
  }
  return result;
}

// Функция для проверки, является ли символ числом
int is_operand(char c) {
  int result = 0;
  if ((c >= '0' && c <= '9') || c == '.') {
    result = 1;
  }
  return result;
}

// Функция для определения приоритета оператора
int get_priority(char oper) {
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
double perform_operation(double operand1, double operand2, char oper) {
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
double calculate_expression(const char* expression) {
  // char* tmp_expression;
  // tmp_expression = strdup(expression);
  //    if (tmp_expression[strlen(tmp_expression)-1] == '\n') {
  //       tmp_expression[strlen(tmp_expression)-1] = '\0';
  //    }

  double operand_stack[255];  // Стек для чисел
  char operator_stack[255];   // Стек для операторов
  int operand_top = -1;
  int operator_top = -1;
  int unary_minus = 0;  // Флаг для унарного минуса
  int unary_plus = 0;   // Флаг для унарного плюса

  for (size_t i = 0; i < strlen(expression); i++) {
    char current_char = expression[i];

    // Если текущий символ - число, добавляем его в стек операндов
    if (is_operand(current_char)) {
      operand_top++;
      operand_stack[operand_top] = atof(&expression[i]);

      // Увеличиваем индекс i, чтобы пропустить всё число
      while (is_operand(expression[i])) {
        i++;
      }

      i--;  // Возвращаемся назад на символ, который не является числом

      // Если перед числом стоит унарный минус, меняем знак числа в стеке
      if (unary_minus) {
        operand_stack[operand_top] = -operand_stack[operand_top];
        unary_minus = 0;  // Сбрасываем флаг унарного минуса
      }

      // Если перед числом стоит унарный плюс, ничего не делаем
      if (unary_plus) {
        unary_plus = 0;  // Сбрасываем флаг унарного плюса
      }
    }

    // Если текущий символ - оператор
    else if (is_operator(current_char)) {
      // Обработка для унарного минуса и плюса
      if ((current_char == '-' || current_char == '+')) {
        if (i == 0 || expression[i - 1] == '(' ||
            is_operator(expression[i - 1])) {
          if (current_char == '-') {
            unary_minus = 1;
          } else if (current_char == '+') {
            unary_plus = 1;
          }
          continue;
        }
      }

      // Если стек операторов пуст, добавляем текущий оператор в стек
      if (operator_top == -1) {
        operator_top++;
        operator_stack[operator_top] = current_char;
      }
      // Если стек операторов не пуст и текущий оператор имеет более высокий
      // приоритет, чем оператор на вершине стека
      else if (get_priority(current_char) >
               get_priority(operator_stack[operator_top])) {
        operator_top++;
        operator_stack[operator_top] = current_char;
      }
      // Если стек операторов не пуст и текущий оператор имеет такой же или
      // более низкий приоритет, чем оператор на вершине стека
      else {
        // Выполняем операцию на вершине стека, пока текущий оператор не получит

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
    }

    // Если текущий символ - открывающая скобка, добавляем ее в стек операторов
    else if (current_char == '(') {
      operator_top++;
      operator_stack[operator_top] = current_char;
    }

    // Если текущий символ - закрывающая скобка
    else if (current_char == ')') {
      // Выполняем операции на вершине стека до открывающей скобки
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
    }
  }

  // Выполняем оставшиеся операции на вершине стека
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

  // Возвращаем результат вычислений
  return operand_stack[operand_top];
}

// int main() {
//     char expression[256];

//    printf("Enter an arithmetic expression: ");
//    fgets(expression, sizeof(expression), stdin);

//    // Удаляем символ новой строки из ввода
//    if (expression[strlen(expression)-1] == '\n') {
//        expression[strlen(expression)-1] = '\0';
//    }

//    float result = calculate_expression(expression);

//    printf("Result: %.7f\n", result);

//    return 0;
//}
