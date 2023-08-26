#include "credit_calc.h"

double A_MonthlyPayment(double credit_sum, double period, double percent) {
  double monthly = 0.0;
  double month_percent = (percent / 12.0) / 100.0;
  monthly = (credit_sum * month_percent * pow((1.0 + month_percent), period)) /
            ((pow((1 + month_percent), period) - 1.0));
  monthly = round(monthly * 100) / 100;
  return monthly;
}

double A_Overpayment(double credit_sum, double period, double monthly) {
  double overpayment = 0.0;
  overpayment = (monthly * period) - credit_sum;
  overpayment = round(overpayment * 100) / 100;
  return overpayment;
}

double TotalPayout(double credit_sum, double overpay) {
  double total = 0.0;
  total = credit_sum + overpay;
  return total;
}

double D_MonthlyPayment(double credit_sum, double period, double percent) {
  double monthly = 0.0;
  double month_percent = (percent / 12.0) / 100.0;
  monthly = (credit_sum / period) + (credit_sum * month_percent);
  return monthly;
}

double D_Last(double credit_sum, double period, double monthly,
              double percent) {
  double last_payment = 0.0;
  double month_percent = (percent / 12.0 / 100.0);
  double total_percent = month_percent * (period - 1);
  last_payment =
      credit_sum + (credit_sum * total_percent) - (monthly * (period - 1));
  last_payment += last_payment * month_percent;
  return last_payment;
}

double D_Overpayment(double credit_sum, double period, double percent) {
  double overpayment = 0.0;
  double body_payment = (credit_sum / period);
  double remaining_debt = credit_sum;

  for (double i = 0; i < period; i++) {
    double interest_payment = remaining_debt * (percent / 12.0 / 100.0);
    remaining_debt -= body_payment;
    overpayment += interest_payment;
  }
  overpayment = round(overpayment * 100) / 100;
  return overpayment;
}
