#include "credit_calc.h"

// Аннуитетный ежемесячный платеж
double A_MonthlyPayment(double credit_sum, double period, double percent) {
  double monthly = 0.0;
  double month_percent =
      (percent / 12.0) / 100.0;  // Рассчитываем процентную ставку в месяц
  monthly = (credit_sum * month_percent * pow((1.0 + month_percent), period)) /
            ((pow((1 + month_percent), period) - 1.0));
  monthly = round(monthly * 100) / 100;
  return monthly;
}

// Переплата при аннуитетном платеже
double A_Overpayment(double credit_sum, double period, double monthly) {
  double overpayment = 0.0;
  overpayment =
      (monthly * period) - credit_sum;  // Вычисляем переплату по формуле
  overpayment = round(overpayment * 100) / 100;
  return overpayment;
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
      (percent / 12.0) / 100.0;  // периодическая процентная ставка
  monthly = (credit_sum / period) + (credit_sum * month_percent);
  return monthly;
}

double D_Last(double credit_sum, double period, double monthly,
              double percent) {
  double last_payment = 0.0;
  double month_percent =
      (percent / 12.0 / 100.0);  // периодическая процентная ставка
  double total_percent =
      month_percent * (period - 1);  // общая сумма начисленных процентов
  last_payment =
      credit_sum + (credit_sum * total_percent) - (monthly * (period - 1));
  last_payment += last_payment * month_percent;
  return last_payment;
}

// Переплата при дифференцированном платеже
double D_Overpayment(double credit_sum, double period, double percent) {
  double overpayment = 0.0;
  double body_payment =
      (credit_sum / period);  // сумма погашения тела кредита каждый месяц
  double remaining_debt = credit_sum;  // оставшаяся сумма долга

  for (double i = 0; i < period; i++) {
    double interest_payment = remaining_debt * (percent / 12.0 / 100.0);
    remaining_debt -= body_payment;
    overpayment +=
        interest_payment;  // добавляем сумму погашения процентов к переплате
  }
  overpayment = round(overpayment * 100) / 100;
  return overpayment;
}
