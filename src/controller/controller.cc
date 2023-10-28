#include "controller.h"

std::tuple<double, bool> s21::Controller::Calculate(std::string &str_input) {
  return calc->Calculate(str_input);
}

bool s21::Controller::CreditCalculate(std::string &credit_data,
                                      double *max_payment, double *min_payment,
                                      double *overpayment, double *total_sum) {
  return credit_calc->CreditCalculate(credit_data, max_payment, min_payment,
                                     overpayment, total_sum);
}
