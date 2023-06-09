#include "controller.h"

double s21::Controller::Calculate(std::string &str_input, bool *status) {
  s21::Calculations calc;
  return calc.Calculate(str_input, status);
}

bool s21::Controller::CreditCalculate(std::string &credit_data,
                                      double *max_payment, double *min_payment,
                                      double *overpayment, double *total_sum) {
  s21::CreditCalculations credit_calc;
  return credit_calc.CreditCalculate(credit_data, max_payment, min_payment,
                                     overpayment, total_sum);
}
