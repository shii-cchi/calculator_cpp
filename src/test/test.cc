#include <gtest/gtest.h>

#include "../logic/calculations.h"
#include "../logic/credit_calculations.h"

TEST(test_1, True) {
  std::string str = "7 + 2 * (cos(24) + log(10))";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 9.84835801) <= EPS));
}

TEST(test_2, True) {
  std::string str = "sin(2) + tan(2) - ln(2) * (54 mod 4)";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - (-2.66203680)) <= EPS));
}

TEST(test_3, True) {
  std::string str = "asin(0.1) * acos(0.2)";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 0.13717311) <= EPS));
}

TEST(test_4, True) {
  std::string str = "sqrt(+32) + 2^4 + atan(-3 / 4)";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 21.01335314) <= EPS));
}

TEST(test_5, True) {
  std::string str = "2 * x + -x";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status);
}

TEST(test_6, False) {
  std::string str = "xx";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_7, False) {
  std::string str = "0..34 + 2";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_8, True) {
  std::string str = "0. + 5";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 5) <= EPS));
}

TEST(test_9, False) {
  std::string str = "5 + .";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_10, True) {
  std::string str = "5 + 1.";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 6) <= EPS));
}

TEST(test_11, False) {
  std::string str = ". + 5";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_12, True) {
  std::string str = "5 + .1";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 5.1) <= EPS));
}

TEST(test_13, True) {
  std::string str = "0.5 + 5";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  double value = std::get<0>(result);
  bool status = std::get<1>(result);
  ASSERT_TRUE(status && (fabs(value - 5.5) <= EPS));
}

TEST(test_14, False) {
  std::string str = "+ - * ";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_15, False) {
  std::string str = "2 + ";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_16, False) {
  std::string str = "2 * ((3) + 4()";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_17, False) {
  std::string str = "2)()";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_18, False) {
  std::string str = "2sin(2)";
  s21::Calculations calc;

  auto result = calc.Calculate(str);
  bool status = std::get<1>(result);
  ASSERT_FALSE(status);
}

TEST(test_19, True) {
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  std::string str = "500000 5 12 a";
  s21::CreditCalculations calc;

  bool status = calc.CreditCalculate(str, &max_payment, &min_payment,
                                     &overpayment, &total_sum);
  ASSERT_TRUE(status && fabs(max_payment - 11122) <= 1 &&
              fabs(min_payment - 0) <= 1 && fabs(overpayment - 167333) <= 1 &&
              fabs(total_sum - 667333) <= 1);
}

TEST(test_20, True) {
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  std::string str = "500000 5 12 d";
  s21::CreditCalculations calc;

  bool status = calc.CreditCalculate(str, &max_payment, &min_payment,
                                     &overpayment, &total_sum);
  ASSERT_TRUE(status && fabs(max_payment - 13333) <= 1 &&
              fabs(min_payment - 8416) <= 1 &&
              fabs(overpayment - 152500) <= 1 && fabs(total_sum - 652500) <= 1);
}

TEST(test_21, False) {
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  std::string str = "500000 5 12a d";
  s21::CreditCalculations calc;

  bool status = calc.CreditCalculate(str, &max_payment, &min_payment,
                                     &overpayment, &total_sum);
  ASSERT_FALSE(status);
}

TEST(test_22, False) {
  double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
  std::string str = "500000 5 12";
  s21::CreditCalculations calc;

  bool status = calc.CreditCalculate(str, &max_payment, &min_payment,
                                     &overpayment, &total_sum);
  ASSERT_FALSE(status);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}