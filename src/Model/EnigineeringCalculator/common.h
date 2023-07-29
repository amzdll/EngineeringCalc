#ifndef CPP3_SMARTCALC_V2_0_1_COMMON_H
#define CPP3_SMARTCALC_V2_0_1_COMMON_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "iostream"
namespace s21 {
typedef enum Type {
  t_num,
  t_bracket_l,
  t_bracket_r,
  t_plus,
  t_minus,
  t_div,
  t_mul,
  t_mod,
  t_pow,
  t_cos,
  t_sin,
  t_tan,
  t_acos,
  t_asin,
  t_atan,
  t_sqrt,
  t_ln,
  t_log,
  t_variable
} type_t;

struct lexeme_t {
  lexeme_t() = default;
  lexeme_t(double value, int priority, type_t type)
      : value(value), priority(priority), type(type){};
  double value;
  int priority;
  type_t type;
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_1_COMMON_H
