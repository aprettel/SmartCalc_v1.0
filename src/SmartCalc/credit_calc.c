#include "credit_calc.h"

// Аннуитетный ежемесячный платеж
double A_MonthlyPayment(double credit_sum, int period, double percent) {
  double monthly = 0.0;
  double month_percent =
      (percent / 12 / 100);  // Рассчитываем процентную ставку в месяц
  monthly = (credit_sum * month_percent * pow((1 + month_percent), period)) /
            ((pow((1 + month_percent), period) - 1));

  return monthly;
}

// Переплата при аннуитетном платеже
double A_Overpayment(double credit_sum, int period, double monthly) {
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
double D_MonthlyPayment(double credit_sum, int period, double percent) {
  double monthly = 0.0;
  double month_percent =
      (percent / 12 / 100);  // периодическая процентная ставка

  monthly = (credit_sum / period) + (credit_sum * month_percent);

  return monthly;
}

// Переплата при дифференцированном платеже
double D_Overpayment(double credit_sum, int period, double percent) {
  double overpayment = 0.0;
  double body_payment =
      (credit_sum / period);  // сумма погашения тела кредита каждый месяц
  double remaining_debt = credit_sum;  // оставшаяся сумма долга

  for (int i = 0; i < period; i++) {
    double interest_payment = remaining_debt * (percent / 12 / 100);
    remaining_debt -= body_payment;  // уменьшаем оставшуюся сумму долга на
                                     // сумму погашения тела кредита
    overpayment +=
        interest_payment;  // добавляем сумму погашения процентов к переплате
  }

  return overpayment;
}

// Выбор типа ежемесячных платежей
// double payment_type(char* type_pay, double credit_sum, int period,
//                   double percent) {
//     double result = 0;

//   if (strcmp(type_pay, "аннуитетный") == 0) {
//     // result = 1;
//     double monthly = A_MonthlyPayment(credit_sum, period, percent);
//     printf("Ежемесячный платеж: %.2lf\n", monthly);

//     double overpay = A_Overpayment(credit_sum, period, monthly);
//     printf("Начисленные проценты: %.2lf\n", overpay);

//     double total = TotalPayout(credit_sum, overpay);
//     printf("Долг + проценты: %.2lf\n", total);

//   } else if (strcmp(type_pay, "дифференцированный") == 0) {
//     // result = 2;
//     double monthly = D_MonthlyPayment(credit_sum, period, percent);
//     printf("Ежемесячный платеж: %.2lf\n", monthly);

//     double overpay = D_Overpayment(credit_sum, period, percent);
//     printf("Начисленные проценты: %.2lf\n", overpay);

//     double total = TotalPayout(credit_sum, overpay);
//     printf("Долг + проценты: %.2lf\n", total);
//   } else {
//     printf("Некорректный тип платежа\n");
//     exit(EXIT_FAILURE);
//   }
//     return result;
// }

// int main() {
//  double credit_sum = 0.0;
//  scanf("%lf", &credit_sum);

//  int period = 0;
//  scanf("%d", &period);

//  double percent = 0.0;
//  scanf("%lf", &percent);

 // char* annuity = "аннуитетный";
 // char* different "дифференцированный";

//  char type_pay[25];
//  scanf("%s", type_pay);
//  payment_type(type_pay, credit_sum, period, percent);
 //   printf("%d\n", payment_type(type_pay, credit_sum, period, percent));

  //  double monthlyA = A_MonthlyPayment(credit_sum, period, percent);
  //  printf("%.2lf\n", monthlyA);

  // double monthlyD = D_MonthlyPayment(credit_sum, period, percent);
  // printf("%.2lf\n", monthlyD);

 //   double overpay = D_Overpayment(credit_sum, period, percent);
 //   printf("%.2lf\n", overpay);

 //   double total = TotalPayout(credit_sum, overpay);
 //   printf("%.2lf\n", total);

//  return 0;
// }
