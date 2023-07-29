#ifndef CPP3_SMARTCALC_V2_0_1_CONVERTER_H
#define CPP3_SMARTCALC_V2_0_1_CONVERTER_H

#include "../common.h"

namespace s21 {
class Converter {
 public:
  using operand_type = std::pair<char, lexeme_t>;
  using function_type = std::pair<std::string, lexeme_t>;
  using list = std::list<lexeme_t>;

  static list StringToPostfix(std::string expression);

 private:
  static void InitMapsOfOperands(std::map<char, lexeme_t> &operations,
                                 std::map<std::string, lexeme_t> &functions);
  static list StringToInfix(std::string expression);
  static void LexemeOfNumber(const std::string &expression, size_t &position,
                             list &list_of_expression);
  static void LexemeOfOperations(const std::string &expression,
                                 size_t &position, list &list_of_expression,
                                 std::map<char, lexeme_t> operations);
  static void LexemeOfFunctions(std::string &expression, size_t &position,
                                list &list_of_expression,
                                std::map<std::string, lexeme_t> functions);
  static void ConvertOperationToPostfix(lexeme_t lexeme, list &temporary_list,
                                        list &output_list);
  static void ConvertBracketsToPostfix(lexeme_t lexeme, list &temporary_list,
                                       list &output_list);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CONVERTER_H
