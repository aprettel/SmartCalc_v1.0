#include <check.h>

#include "calculator.h"

START_TEST(smart_calc_1) {
  char result[255] = {'\0'};
  infixToRPN("1*2+3", result);
  ck_assert_str_eq(result, "1 2 * 3 + ");
}
END_TEST

START_TEST(smart_calc_2) {
  char result[255] = {'\0'};
  infixToRPN("1+2*3", result);
  ck_assert_str_eq(result, "1 2 3 * + ");
}
END_TEST

START_TEST(smart_calc_3) {
  char result[255] = {'\0'};
  infixToRPN("1+2*3/4-5", result);
  ck_assert_str_eq(result, "1 2 3 * 4 / + 5 - ");
}
END_TEST

START_TEST(smart_calc_4) {
  char result[255] = {'\0'};
  infixToRPN("1+2*(3/4-5)", result);
  ck_assert_str_eq(result, "1 2 3 4 / 5 - * + ");
}
END_TEST

START_TEST(smart_calc_5) {
  char result[255] = {'\0'};
  infixToRPN("(1+2)/44*(3/(4-5))", result);
  ck_assert_str_eq(result, "1 2 + 44 / 3 4 5 - / * ");
}
END_TEST

START_TEST(smart_calc_6) {
  char result[255] = {'\0'};
  infixToRPN("(1+2)/(44*(3/(4-5)))", result);
  ck_assert_str_eq(result, "1 2 + 44 3 4 5 - / * / ");
}
END_TEST

START_TEST(smart_calc_9) {
  char result[255] = {'\0'};
  infixToRPN("2.34-43.123", result);
  ck_assert_str_eq(result, "2.34 43.123 - ");
}
END_TEST

START_TEST(smart_calc_10) {
  char result[255] = {'\0'};
  infixToRPN("2.34-43.123/(456.312-654)*123.543-(42.123+534.432)", result);
  ck_assert_str_eq(
      result, "2.34 43.123 456.312 654 - / 123.543 * - 42.123 534.432 + - ");
}
END_TEST

START_TEST(smart_calc_18) {
  char result[255] = {'\0'};
  infixToRPN("2^123.543", result);
  // printf("result:\n%s\n", result);
  ck_assert_str_eq(result, "2 123.543 ^ ");
}
END_TEST

START_TEST(smart_calc_19) {
  char result[255] = {'\0'};
  infixToRPN("(2+5/3)^123.543", result);
  // printf("result:\n%s\n", result);
  ck_assert_str_eq(result, "2 5 3 / + 123.543 ^ ");
}
END_TEST

START_TEST(smart_calc_20) {
  char result[255] = {'\0'};
  infixToRPN("-(-2)+3", result);
  // printf("result:\n%s\n", result);
  ck_assert_str_eq(result, "--2 0 - 3 + 0 - ");
}
END_TEST

START_TEST(smart_calc_21) {
  char result[255] = {'\0'};
  infixToRPN("10%3", result);
  // printf("result:\n%s\n", result);
  ck_assert_str_eq(result, "10 3 % ");
}
END_TEST

START_TEST(smart_calc_22) {
  char result[255] = {'\0'};
  infixToRPN("15%4", result);
  // printf("result:\n%s\n", result);
  ck_assert_str_eq(result, "15 4 % ");
}
END_TEST

START_TEST(smart_calc_24) {
  char result[255] = {'\0'};
  infixToRPN("0", result);
  ck_assert_str_eq(result, "0 ");
}
END_TEST

START_TEST(smart_calc_26) {
  char result[255] = {'\0'};
  infixToRPN("sin(cos(5))", result);
  // printf("\n%s\n", result);
  ck_assert_str_eq(result, "5 c s ");
}
END_TEST

START_TEST(smart_calc_27) {
  char result[255] = {'\0'};
  infixToRPN("sqrt(5)", result);
  ck_assert_str_eq(result, "5 Q ");
}
END_TEST

START_TEST(smart_calc_29) {
  char result[255] = {'\0'};
  infixToRPN("-1/(-1)", result);
  ck_assert_str_eq(result, "-1 -1 0 - / 0 - ");
}
END_TEST

START_TEST(smart_calc_31) {
  char result[255] = {'\0'};
  infixToRPN("(-1)/(-1)", result);
  ck_assert_str_eq(result, "-1 0 - -1 0 - / ");
}
END_TEST

START_TEST(smart_calc_32) {
  char result[255] = {'\0'};
  infixToRPN("sin(45)", result);
  ck_assert_str_eq(result, "45 s ");
}
END_TEST

START_TEST(smart_calc_33) {
  char result[255] = {'\0'};
  infixToRPN("cos(45)", result);
  ck_assert_str_eq(result, "45 c ");
}
END_TEST

START_TEST(smart_calc_34) {
  char result[255] = {'\0'};
  infixToRPN("asin(45)", result);
  ck_assert_str_eq(result, "45 S ");
}
END_TEST

START_TEST(smart_calc_35) {
  char result[255] = {'\0'};
  infixToRPN("tan(45)", result);
  ck_assert_str_eq(result, "45 t ");
}
END_TEST

START_TEST(smart_calc_36) {
  char result[255] = {'\0'};
  infixToRPN("atan(45)", result);
  ck_assert_str_eq(result, "45 T ");
}
END_TEST

START_TEST(smart_calc_37) {
  char result[255] = {'\0'};
  infixToRPN("sqrt(45)", result);
  ck_assert_str_eq(result, "45 Q ");
}
END_TEST

START_TEST(smart_calc_38) {
  char result[255] = {'\0'};
  infixToRPN("ln(45)", result);
  ck_assert_str_eq(result, "45 l ");
}
END_TEST

START_TEST(smart_calc_39) {
  char result[255] = {'\0'};
  infixToRPN("log(45)", result);
  ck_assert_str_eq(result, "45 L ");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, smart_calc_1);
  tcase_add_test(tc1_1, smart_calc_2);
  tcase_add_test(tc1_1, smart_calc_3);
  tcase_add_test(tc1_1, smart_calc_4);
  tcase_add_test(tc1_1, smart_calc_5);
  tcase_add_test(tc1_1, smart_calc_6);

  tcase_add_test(tc1_1, smart_calc_9);
  tcase_add_test(tc1_1, smart_calc_10);

  tcase_add_test(tc1_1, smart_calc_18);
  tcase_add_test(tc1_1, smart_calc_19);
  tcase_add_test(tc1_1, smart_calc_20);
  tcase_add_test(tc1_1, smart_calc_21);
  tcase_add_test(tc1_1, smart_calc_22);

  tcase_add_test(tc1_1, smart_calc_24);

  tcase_add_test(tc1_1, smart_calc_26);
  tcase_add_test(tc1_1, smart_calc_27);

  tcase_add_test(tc1_1, smart_calc_29);

  tcase_add_test(tc1_1, smart_calc_31);
  tcase_add_test(tc1_1, smart_calc_32);
  tcase_add_test(tc1_1, smart_calc_33);
  tcase_add_test(tc1_1, smart_calc_34);
  tcase_add_test(tc1_1, smart_calc_35);
  tcase_add_test(tc1_1, smart_calc_36);
  tcase_add_test(tc1_1, smart_calc_37);
  tcase_add_test(tc1_1, smart_calc_38);
  tcase_add_test(tc1_1, smart_calc_39);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
