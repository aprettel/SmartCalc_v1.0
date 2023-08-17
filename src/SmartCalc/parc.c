#include "smart_calc.h"

typedef struct stackDouble {
  double number;
  struct stackDouble *next;
} stackD;

stackD *initStakDouble(double *value) {
  stackD *tmp = (stackD *)malloc(sizeof(stackD));
  tmp->next = NULL;
  tmp->number = *value;
  return tmp;
}

void pushDouble(stackD **stack, double *value) {
  stackD *tmp = initStakDouble(value);
  tmp->next = *stack;
  *stack = tmp;
}

double popDouble(stackD **stack) {
  double number = NAN;
  if (*stack) {
    stackD *tmp = *stack;
    *stack = tmp->next;
    number = tmp->number;
    free(tmp);
  }
  return number;
}

void pushList(list *stack_list, token stack_token) {
  stack_list->count_token++;
  stack_list->token_list[stack_list->count_token] = stack_token;
}
token popList(list *stack_list) {
  token temp = {0};
  temp = stack_list->token_list[stack_list->count_token];
  stack_list->count_token--;
  return temp;
}

char serchFuncs(char *str, int *count) {
  char return_value;
  if (strncmp(str, "sin", 3) == 0) {
    *count = 3;
    return_value = 's';
  } else if (strncmp(str, "cos", 3) == 0) {
    *count = 3;
    return_value = 'c';
  } else if (strncmp(str, "tan", 3) == 0) {
    *count = 3;
    return_value = 't';
  } else if (strncmp(str, "log", 3) == 0) {
    *count = 3;
    return_value = 'l';
  } else if (strncmp(str, "sqrt", 4) == 0) {
    *count = 4;
    return_value = 'q';
  } else if (strncmp(str, "ln", 2) == 0) {
    *count = 2;
    return_value = 'L';
  } else if (strncmp(str, "atan", 4) == 0) {
    *count = 4;
    return_value = 'T';
  } else if (strncmp(str, "acos", 4) == 0) {
    *count = 4;
    return_value = 'C';
  } else if (strncmp(str, "asin", 4) == 0) {
    *count = 4;
    return_value = 'S';
  } 
  return return_value;
}

bool makeList(char *str, list *infix) {
  int return_value = true;
  token input_value = {0};
  int i = 0;
  while (*str) {
    if (isdigit(*str) && return_value == true) {
      input_value.ptr = str;
      input_value.priority = NUM;
      pushList(infix, input_value);
      str++;
      while (isdigit(*str) || *str == '.') {
        str++;
      }
    } else if (*str == '+' || *str == '-') {
      input_value.ptr = str;
      input_value.priority = ADD;
      pushList(infix, input_value);
      str++;
    } else if (*str == '*' || *str == '/' || *str == '%') {
      input_value.ptr = str;
      input_value.priority = MUL;
      pushList(infix, input_value);
      str++;
    } else if (*str == '^') {
      input_value.ptr = str;
      input_value.priority = POW;
      pushList(infix, input_value);
      str++;
    } else if (*str >= 'a' && *str <= 'z') {
      int iter = 0;
      if (serchFuncs(str, &iter)) {
        input_value.ptr = str;
        input_value.priority = MUL;
        pushList(infix, input_value);
        str += iter;
      } else {
        return_value = false;
      }
    } else if (*str == '(') {
      input_value.ptr = str;
      input_value.priority = OP_BR;
      pushList(infix, input_value);
      str++;
    } else if (*str == ')') {
      input_value.ptr = str;
      input_value.priority = CL_BR;
      pushList(infix, input_value);
      str++;
    } else {
      return_value = false;
    }
  }
  return return_value;
}

void reverPolNot(list *infix, list *polish) {
  list tmp_list = {{0}, -1};
  int count_loop = infix->count_token;
  for (int i = 0; i <= count_loop; i++) {
    if (infix->token_list[i].priority == OP_BR) {
      // while (infix->token_list[i].priority != CL_BR) {
      //   if (infix->token_list[i].priority != CL_BR ||
      //       infix->token_list[i].priority != OP_BR) {
      //     polish->token_list[polish->count_token] = infix->token_list[i];
      //     i++;
      //     polish->count_token++;
      //   }
      //   i++;
      // }
    } else if (infix->token_list[i].priority == NUM) {
      pushList(polish, infix->token_list[i]);
    } else {
      if (tmp_list.count_token == -1) {
        pushList(&tmp_list, infix->token_list[i]);
      } else if (tmp_list.token_list[tmp_list.count_token].priority >=
                 infix->token_list[i].priority) {
        while (tmp_list.token_list[tmp_list.count_token].priority >=
               infix->token_list[i].priority) {
          pushList(polish, tmp_list.token_list[tmp_list.count_token]);
          popList(&tmp_list);
        }
        pushList(&tmp_list, infix->token_list[i]);
      } else {
        pushList(&tmp_list, infix->token_list[i]);
      }
    }
  }
  while (tmp_list.count_token > -1) {
    pushList(polish, tmp_list.token_list[tmp_list.count_token]);
    tmp_list.count_token--;
  }
}

double isOperation(char op, double operand1, double operand2) {
  double result = 0.0;
  switch (op) {
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
  }
  return result;
}

// double isFunc(char *op, double operand) {
//   int iter = 0;
//   char func = ' ';
//   double result = 0.0;
//   func = serchFuncs(op, &iter);
//   switch (func) {
//     case 's':
//     result = sin(operand);
//     break;
//     case 'c':
//     result = cos(operand);
//     break;
//     case 't':
//     result = tan(operand);
//     break;
//     case 'l':
//     result = log(operand);
//     break;
//     case 'q':
//     result = sqrt(operand);
//     break;
//     case 'L':
//     result = log10(operand);
//     break;
//     case 'T':
//     result = atan(operand);
//     break;
//     case 'C':
//     result = acos(operand);
//     break;
//     case 'S':
//     result = asin(operand);
//     break;
//   }
//   return result;
// }

void calc(list *polish, double *result) {
  int loop_count = polish->count_token;
  double number = 0.0;
  double operand1 = 0.0, operand2 = 0.0;
  stackD *num = {0};
  for (int i = 0; i <= loop_count; i++) {
    if (polish->token_list[i].priority == NUM) {
      number = strtod(polish->token_list[i].ptr, &polish->token_list[i].ptr);
      pushDouble(&num, &number);
      printf("%lf\n", num->number);
    } else if (polish->token_list[i].priority == ADD ||
               polish->token_list[i].priority == MUL ||
               polish->token_list[i].priority == POW) {
      operand2 = popDouble(&num);
      operand1 = popDouble(&num);
      double ans = isOperation(*polish->token_list[i].ptr, operand1, operand2);
      pushDouble(&num, &number);
    } 
    // else if (polish->token_list[i].priority == FUNC) {
    //   operand1 = popDouble(&num);
    //   number = isFunc(polish->token_list[i].ptr, operand1);
    //   pushDouble(&num, &number);
    // }
  }
  *result = popDouble(&num);
}

int main() {
  char str[] = "39-1^2*4";
  list infix = {{0}, -1};
  list polish = {{0}, -1};
  double num = 0.0;
  makeList(str, &infix);
  reverPolNot(&infix, &polish);
  for (int i = 0; i <= polish.count_token; i++) {
    printf("%c\n", *polish.token_list[i].ptr);
  }
  calc(&polish, &num);
  printf("%lf", num);
  return 0;
}