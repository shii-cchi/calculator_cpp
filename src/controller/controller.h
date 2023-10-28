#ifndef CPP3_SMARTCALC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_CONTROLLER_CONTROLLER_H_

#include "../logic/calculations.h"
#include "../logic/credit_calculations.h"

namespace s21 {

class Controller {
 public:
  std::tuple<double, bool> Calculate(std::string &str_input);
  bool CreditCalculate(std::string &credit_data, double *max_payment,
                       double *min_payment, double *overpayment,
                       double *total_sum);

 private:
  s21::Calculations calc;
  s21::CreditCalculations credit_calc;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_CONTROLLER_CONTROLLER_H_
