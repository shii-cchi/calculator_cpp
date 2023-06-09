#ifndef SRC_CREDIT_CALCULATIONS_H_
#define SRC_CREDIT_CALCULATIONS_H_

#include <cmath>
#include <string>

#define LEN 255

namespace s21 {

class CreditCalculations {
 public:
  bool CreditCalculate(std::string &credit_data, double *max_payment,
                       double *min_payment, double *overpayment,
                       double *total_sum);

 private:
  typedef struct credit_data {
    double sum;
    double percent;
    int term;
    char type;
    double max_payment;
    double min_payment;
    double overpayment;
    double total_sum;
  } credit_t;

  void Clear(credit_t *credit);
  void Calculate(credit_t *credit);
};
}  // namespace s21

#endif  // SRC_CREDIT_CALCULATIONS_H_