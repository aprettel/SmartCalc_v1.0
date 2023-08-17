#ifndef SMART_CALC_H
#define SMART_CALC_H

#define MAX_SIZE 255

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enum for priority

enum {
  NUM = 1,
  OP_BR = 2,
  ADD = 3,
  MUL = 4,
  POW = 5,
  FUNC = 6,
  CL_BR = 7
} priority;

// typedef struct stackRPN {
//   char simbol;
//   struct stackRPN *next;
// } stackP;

typedef struct createToken {  // rename
  int priority;
  char* ptr;  // rename
} token;

typedef struct createList {  // rename
  token token_list[MAX_SIZE];
  int count_token;
} list;

#endif  // SMART_CALC_H