#include <gtest/gtest.h>

#include "../calculations.h"

TEST(test_1, True) {
    double result = 0;
    std::string str = "7 + 2 * (cos(24) + log(10))";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 9.84835801) <= EPS));
}

TEST(test_2, True) {
    double result = 0;
    std::string str = "sin(2) + tan(2) - ln(2) * (54 mod 4)";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - (-2.66203680)) <= EPS));
}

TEST(test_3, True) {
    double result = 0;
    std::string str = "asin(0.1) * acos(0.2)";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 0.13717311) <= EPS));
}

TEST(test_4, True) {
    double result = 0;
    std::string str = "sqrt(+32) + 2^4 + atan(-3 / 4)";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 21.01335314) <= EPS));
}

TEST(test_5, True) {
    double result = 0;
    std::string str = "2 * x + -x";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 0) <= EPS));
}

TEST(test_6, True) {
    double result = 0;
    std::string str = "xx";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_7, True) {
    double result = 0;
    std::string str = "0..34 + 2";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_8, True) {
    double result = 0;
    std::string str = "0. + 5";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 5) <= EPS));
}

TEST(test_9, True) {
    double result = 0;
    std::string str = "5 + .";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_10, True) {
    double result = 0;
    std::string str = "5 + 1.";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 6) <= EPS));
}

TEST(test_11, True) {
    double result = 0;
    std::string str = ". + 5";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_12, True) {
    double result = 0;
    std::string str = "5 + .1";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 5.1) <= EPS));
}

TEST(test_13, True) {
    double result = 0;
    std::string str = "0.5 + 5";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 1 && (fabs(result - 5.5) <= EPS));
}

TEST(test_14, True) {
    double result = 0;
    std::string str = "+ - * ";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_15, True) {
    double result = 0;
    std::string str = "2 + ";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_16, True) {
    double result = 0;
    std::string str = "2 * ((3) + 4()";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_17, True) {
    double result = 0;
    std::string str = "2)()";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

TEST(test_18, True) {
    double result = 0;
    std::string str = "2sin(2)";
    s21::Calculations calc;

    int status = calc.Calculate(str, &result);
    ASSERT_TRUE(status == 0 && (fabs(result - 0) <= EPS));
}

// TEST(test_19, True) {
//     double result = 0;
//     std::string str = "sin(2)";
//     s21::Calculations calc;

//     int status = calc.Calculate(str, &result);
//     ASSERT_TRUE(status == 1 && (fabs(result - 0.90929743) <= EPS));
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}