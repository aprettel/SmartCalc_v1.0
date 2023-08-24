#include <check.h>

#include "calculator.h"
#include "credit_calc.h"

START_TEST(rpn_1) {
  char result[255] = {'\0'};
  infixToRPN("1*2+3", result);
  ck_assert_str_eq(result, "1 2 * 3 + ");
}
END_TEST

START_TEST(rpn_2) {
  char result[255] = {'\0'};
  infixToRPN("1+2*3", result);
  ck_assert_str_eq(result, "1 2 3 * + ");
}
END_TEST

START_TEST(rpn_3) {
  char result[255] = {'\0'};
  infixToRPN("1+2*3/4-5", result);
  ck_assert_str_eq(result, "1 2 3 * 4 / + 5 - ");
}
END_TEST

START_TEST(rpn_4) {
  char result[255] = {'\0'};
  infixToRPN("1+2*(3/4-5)", result);
  ck_assert_str_eq(result, "1 2 3 4 / 5 - * + ");
}
END_TEST

START_TEST(rpn_5) {
  char result[255] = {'\0'};
  infixToRPN("(1+2)/44*(3/(4-5))", result);
  ck_assert_str_eq(result, "1 2 + 44 / 3 4 5 - / * ");
}
END_TEST

START_TEST(rpn_6) {
  char result[255] = {'\0'};
  infixToRPN("(1+2)/(44*(3/(4-5)))", result);
  ck_assert_str_eq(result, "1 2 + 44 3 4 5 - / * / ");
}
END_TEST

START_TEST(rpn_7) {
  char result[255] = {'\0'};
  infixToRPN("+3^(5-2)", result);
  ck_assert_str_eq(result, "3 5 2 - ^ ");
}
END_TEST

START_TEST(rpn_9) {
  char result[255] = {'\0'};
  infixToRPN("2.34-43.123", result);
  ck_assert_str_eq(result, "2.34 43.123 - ");
}
END_TEST

START_TEST(rpn_10) {
  char result[255] = {'\0'};
  infixToRPN("2.34-43.123/(456.312-654)*123.543-(42.123+534.432)", result);
  ck_assert_str_eq(
      result, "2.34 43.123 456.312 654 - / 123.543 * - 42.123 534.432 + - ");
}
END_TEST

START_TEST(rpn_18) {
  char result[255] = {'\0'};
  infixToRPN("2^123.543", result);
  ck_assert_str_eq(result, "2 123.543 ^ ");
}
END_TEST

START_TEST(rpn_19) {
  char result[255] = {'\0'};
  infixToRPN("(2+5/3)^123.543", result);
  ck_assert_str_eq(result, "2 5 3 / + 123.543 ^ ");
}
END_TEST

START_TEST(rpn_20) {
  char result[255] = {'\0'};
  infixToRPN("-(-2)+3", result);
  ck_assert_str_eq(result, "--2 0 - 3 + 0 - ");
}
END_TEST

START_TEST(rpn_21) {
  char result[255] = {'\0'};
  infixToRPN("10%3", result);
  ck_assert_str_eq(result, "10 3 % ");
}
END_TEST

START_TEST(rpn_22) {
  char result[255] = {'\0'};
  infixToRPN("15%4", result);
  ck_assert_str_eq(result, "15 4 % ");
}
END_TEST

START_TEST(rpn_23) {
  char result[255] = {'\0'};
  infixToRPN("5 - 2 / 2", result);
  ck_assert_str_eq(result, "5 2 2 / - ");
}
END_TEST

START_TEST(rpn_24) {
  char result[255] = {'\0'};
  infixToRPN("0", result);
  ck_assert_str_eq(result, "0 ");
}
END_TEST

START_TEST(rpn_25) {
  char result[255] = {'\0'};
  infixToRPN("acos(5)", result);
  ck_assert_str_eq(result, "5 C ");
}
END_TEST

START_TEST(rpn_26) {
  char result[255] = {'\0'};
  infixToRPN("sin(cos(5))", result);
  ck_assert_str_eq(result, "5 c s ");
}
END_TEST

START_TEST(rpn_27) {
  char result[255] = {'\0'};
  infixToRPN("sqrt(5)", result);
  ck_assert_str_eq(result, "5 Q ");
}
END_TEST

START_TEST(rpn_28) {
  char result[255] = {'\0'};
  infixToRPN("", result);
  ck_assert_str_eq(result, "");
}
END_TEST

START_TEST(rpn_29) {
  char result[255] = {'\0'};
  infixToRPN("-1/(-1)", result);
  ck_assert_str_eq(result, "-1 -1 0 - / 0 - ");
}
END_TEST

START_TEST(rpn_31) {
  char result[255] = {'\0'};
  infixToRPN("(-1)/(-1)", result);
  ck_assert_str_eq(result, "-1 0 - -1 0 - / ");
}
END_TEST

START_TEST(rpn_32) {
  char result[255] = {'\0'};
  infixToRPN("sin(45)", result);
  ck_assert_str_eq(result, "45 s ");
}
END_TEST

START_TEST(rpn_33) {
  char result[255] = {'\0'};
  infixToRPN("cos(45)", result);
  ck_assert_str_eq(result, "45 c ");
}
END_TEST

START_TEST(rpn_34) {
  char result[255] = {'\0'};
  infixToRPN("asin(45)", result);
  ck_assert_str_eq(result, "45 S ");
}
END_TEST

START_TEST(rpn_35) {
  char result[255] = {'\0'};
  infixToRPN("tan(45)", result);
  ck_assert_str_eq(result, "45 t ");
}
END_TEST

START_TEST(rpn_36) {
  char result[255] = {'\0'};
  infixToRPN("atan(45)", result);
  ck_assert_str_eq(result, "45 T ");
}
END_TEST

START_TEST(rpn_37) {
  char result[255] = {'\0'};
  infixToRPN("sqrt(45)", result);
  ck_assert_str_eq(result, "45 Q ");
}
END_TEST

START_TEST(rpn_38) {
  char result[255] = {'\0'};
  infixToRPN("ln(45)", result);
  ck_assert_str_eq(result, "45 l ");
}
END_TEST

START_TEST(rpn_39) {
  char result[255] = {'\0'};
  infixToRPN("log(45)", result);
  ck_assert_str_eq(result, "45 L ");
}
END_TEST

START_TEST(calc_1) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("3 - 2 * 4", result);
  calc = calculateRPN(result);
  ck_assert_double_eq(calc, -5);
}
END_TEST

START_TEST(calc_2) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("25 % (5 + 3) / 2 ^ 3", result);
  calc = calculateRPN(result);
  ck_assert_double_eq(calc, 0.125);
}
END_TEST

START_TEST(calc_3) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("2 * sqrt(100)", result);
  calc = calculateRPN(result);
  ck_assert_double_eq(calc, 20);
}
END_TEST

START_TEST(calc_4) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("2 * log(100) * (-1)", result);
  calc = calculateRPN(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, -4);
}
END_TEST

START_TEST(calc_5) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("3 - 2 * sin(5) / atan(1)", result);
  calc = calculateRPN(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, 5.4418806);
}
END_TEST

START_TEST(calc_6) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("tan(1) - cos(5) + (asin(1) * acos(-1))", result);
  calc = calculateRPN(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, 6.2085477);
}
END_TEST

START_TEST(calc_7) {
  double calc = 0.0;
  char result[255] = {'\0'};
  infixToRPN("ln(2)", result);
  calc = calculateRPN(result);
  double roundedCalc = round(calc * 10000000) / 10000000;
  ck_assert_double_eq(roundedCalc, 0.6931472);
}
END_TEST

START_TEST(credit_1) {
  double result = 0.0;
  double credit_sum = 100000.0;
  double period = 10.0;  // месяцев
  double percent = 10.0;
  result = A_MonthlyPayment(credit_sum, period, percent);
  ck_assert_double_eq(result, 10464.04);
}
END_TEST

START_TEST(credit_2) {
  double result = 0.0;
  double credit_sum = 10000.0;
  double period = 10.0;  // месяцев
  double monthly = 1046.40;
  result = A_Overpayment(credit_sum, period, monthly);
  ck_assert_double_eq(result, 464.00);
}
END_TEST

START_TEST(credit_3) {
  double result = 0.0;
  double credit_sum = 1000.0;
  double overpay = 46.40;
  result = TotalPayout(credit_sum, overpay);
  ck_assert_double_eq(result, 1046.40);
}
END_TEST

START_TEST(credit_4) {
  double result = 0.0;
  double credit_sum = 123123.0;
  double period = 12.0;  // месяцев
  double percent = 23.0;
  result = D_MonthlyPayment(credit_sum, period, percent);
  double roundedRes = round(result * 100) / 100;
  ck_assert_double_eq(roundedRes, 12620.11);
}
END_TEST

START_TEST(credit_5) {
  double result = 0.0;
  double credit_sum = 123456.0;
  double period = 5.0 * 12.0;  // лет
  double monthly = 4423.84;
  double percent = 23.0;
  result = D_Last(credit_sum, period, monthly, percent);
  double roundedRes = round(result * 100) / 100;
  ck_assert_double_eq(roundedRes, 2097.04);
}
END_TEST

START_TEST(credit_6) {
  double result = 0.0;
  double credit_sum = 123456.0;
  double period = 5.0 * 12.0;  // лет
  double percent = 23.0;
  result = D_Overpayment(credit_sum, period, percent);
  ck_assert_double_eq(result, 72170.32);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, rpn_1);
  tcase_add_test(tc1_1, rpn_2);
  tcase_add_test(tc1_1, rpn_3);
  tcase_add_test(tc1_1, rpn_4);
  tcase_add_test(tc1_1, rpn_5);
  tcase_add_test(tc1_1, rpn_6);
  tcase_add_test(tc1_1, rpn_7);

  tcase_add_test(tc1_1, rpn_9);
  tcase_add_test(tc1_1, rpn_10);

  tcase_add_test(tc1_1, rpn_18);
  tcase_add_test(tc1_1, rpn_19);
  tcase_add_test(tc1_1, rpn_20);
  tcase_add_test(tc1_1, rpn_21);
  tcase_add_test(tc1_1, rpn_22);
  tcase_add_test(tc1_1, rpn_23);
  tcase_add_test(tc1_1, rpn_24);
  tcase_add_test(tc1_1, rpn_25);
  tcase_add_test(tc1_1, rpn_26);
  tcase_add_test(tc1_1, rpn_27);
  tcase_add_test(tc1_1, rpn_28);
  tcase_add_test(tc1_1, rpn_29);

  tcase_add_test(tc1_1, rpn_31);
  tcase_add_test(tc1_1, rpn_32);
  tcase_add_test(tc1_1, rpn_33);
  tcase_add_test(tc1_1, rpn_34);
  tcase_add_test(tc1_1, rpn_35);
  tcase_add_test(tc1_1, rpn_36);
  tcase_add_test(tc1_1, rpn_37);
  tcase_add_test(tc1_1, rpn_38);
  tcase_add_test(tc1_1, rpn_39);

  tcase_add_test(tc1_1, calc_1);
  tcase_add_test(tc1_1, calc_2);
  tcase_add_test(tc1_1, calc_3);
  tcase_add_test(tc1_1, calc_4);
  tcase_add_test(tc1_1, calc_5);
  tcase_add_test(tc1_1, calc_6);
  tcase_add_test(tc1_1, calc_7);

  tcase_add_test(tc1_1, credit_1);
  tcase_add_test(tc1_1, credit_2);
  tcase_add_test(tc1_1, credit_3);
  tcase_add_test(tc1_1, credit_4);
  tcase_add_test(tc1_1, credit_5);
  tcase_add_test(tc1_1, credit_6);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
