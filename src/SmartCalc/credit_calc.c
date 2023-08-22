#include "credit_calc.h"

// Аннуитетный ежемесячный платеж
double A_MonthlyPayment(double credit_sum, double period, double percent) {
  double monthly = 0.0;
  double month_percent =
      (percent / 12.0 / 100.0);  // Рассчитываем процентную ставку в месяц
  monthly = (credit_sum * month_percent * pow((1.0 + month_percent), period)) /
            ((pow((1 + month_percent), period) - 1.0));

  return monthly;
}

// Переплата при аннуитетном платеже
double A_Overpayment(double credit_sum, double period, double monthly) {
  double overpay = 0.0;
  overpay = (monthly * period) - credit_sum;  // Вычисляем переплату по формуле
  return overpay;
}

// Общая выплата
double TotalPayout(double credit_sum, double overpay) {
  double total = 0.0;
  total = credit_sum + overpay;  // Вычисляем общую выплату по формуле

  return total;
}

// Дифференцированный ежемесячный платеж
double D_MonthlyPayment(double credit_sum, double period, double percent) {
  double monthly = 0.0;
  double month_percent =
      (percent / 12.0 / 100.0);  // периодическая процентная ставка

  monthly = (credit_sum / period) + (credit_sum * month_percent);

  return monthly;
}

// Переплата при дифференцированном платеже
double D_Overpayment(double credit_sum, double period, double percent) {
  double overpayment = 0.0;
  double body_payment =
      (credit_sum / period);  // сумма погашения тела кредита каждый месяц
  double remaining_debt = credit_sum;  // оставшаяся сумма долга

  for (double i = 0; i < period; i++) {
    double interest_payment = remaining_debt * (percent / 12.0 / 100.0);
    remaining_debt -= body_payment;  // уменьшаем оставшуюся сумму долга на
                                     // сумму погашения тела кредита
    overpayment +=
        interest_payment;  // добавляем сумму погашения процентов к переплате
  }

  return overpayment;
}
