#include "calc.h"

void credit_calc(struct s21_credit_input *credit_input,
                 struct s21_credit_out *credit_out) {
  if (credit_input->type == 1) {
    // annuity
    long double ps = 0.0;  // interest rate
    ps = (credit_input->percent / (100 * 12));
    credit_out->monthly_payment =
        credit_input->sum * (ps / (1 - pow((1 + ps), -1 * credit_input->term)));
    credit_out->monthly_payment =
        roundl(credit_out->monthly_payment * 100) / 100;
  } else if (credit_input->type == 2) {
    // differentiated
  }
}
