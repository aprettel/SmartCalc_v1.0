#ifndef CREDIT_CALC_H
#define CREDIT_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 255

double A_MonthlyPayment(double credit_sum, int period, double percent);
double A_Overpayment(double credit_sum, int period, double monthly);
double TotalPayout(double credit_sum, double overpay);
double D_MonthlyPayment(double credit_sum, int period, double percent);
double D_Overpayment(double credit_sum, int period, double percent);
double payment_type(char* type_pay, double credit_sum, int period,
                  double percent);

#endif  // CREDIT_CALC_H
