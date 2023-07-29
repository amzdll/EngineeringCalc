#include <gtest/gtest.h>

#include "./Model/EnigineeringCalculator/engineering_calculator_facade.h"

s21::EnigineeringCalculatorFacade model;

TEST(test1, 1) {
  std::string test_string = "3+4*2/(1-5)^2";
  std::string variable = "0";
  std::string answer = "3.500000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), answer);
}

TEST(test2, 2) {
  std::string test_string = "3+4*2";
  std::string variable = "0";
  std::string answer = "11.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), answer);
}

TEST(test3, 3) {
  std::string test_string = "(132+sin(asin(sqrt(ln(log(228.11)))))/122)";
  std::string variable = "0";
  std::string answer = "132.007026";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), answer);
}

TEST(test4, 4) {
  std::string test_string = "4*((-3+2)*2)";
  std::string variable = "2";
  std::string answer = "-8.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), answer);
}

TEST(test5, 5) {
  std::string test_string = "2^2^3";
  std::string variable = "0";
  std::string expected_result = "64.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test6, 6) {
  std::string test_string = "5%(3)";
  std::string variable = "0";
  std::string expected_result = "2.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test7, 7) {
  std::string test_string =
      "(132+sin(asin(sqrt(ln(log(228.11)))))-4*5^6*(123))";
  std::string variable = "0";
  std::string expected_result = "-7687367.142803";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test8, 8) {
  std::string test_string = "sin(2)";
  std::string variable = "0";
  std::string expected_result = "0.909297";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test9, 9) {
  std::string test_string = "(-3)^2";
  std::string variable = "0";
  std::string expected_result = "9.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test10, 10) {
  std::string test_string = "3+4*2/(1-5)^2";
  std::string variable = "0";
  std::string expected_result = "3.500000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test11, 11) {
  std::string test_string = "6^5-14*2";
  std::string variable = "0";
  std::string expected_result = "7748.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test12, 12) {
  std::string test_string = "3+4*2/(1-5)^2";
  std::string variable = "0";
  std::string expected_result = "3.500000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test13, 13) {
  std::string test_string =
      "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))";
  std::string variable = "0";
  std::string expected_result = "10.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test14, 14) {
  std::string test_string = "(8+2*5)/(1+3*2-4)";
  std::string variable = "0";
  std::string expected_result = "6.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test15, 15) {
  std::string test_string = "1+2+3+4*5*6^7";
  std::string variable = "0";
  std::string expected_result = "5598726.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test16, 16) {
  std::string test_string = "3-(-3)";
  std::string variable = "0";
  std::string expected_result = "6.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test17, 17) {
  std::string test_string = "15+75*1/3-42+3^3";
  std::string variable = "0";
  std::string expected_result = "25.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test18, 18) {
  std::string test_string = "qwerty";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test19, 19) {
  std::string test_string = "";
  std::string variable = "0";
  std::string expected_result = "0.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test20, 20) {
  std::string test_string = "()";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test21, 21) {
  std::string test_string = "3+4*";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test22, 22) {
  std::string test_string = "sin()";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test23, 23) {
  std::string test_string = "5/0";
  std::string variable = "0";
  std::string expected_result = "inf";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test24, 24) {
  std::string test_string = "sqrt(-1)";
  std::string variable = "0";
  std::string expected_result = "nan";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test25, 25) {
  std::string test_string = "log(0)";
  std::string variable = "0";
  std::string expected_result = "-inf";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test26, 26) {
  std::string test_string = "1 + + 2";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test27, 27) {
  std::string test_string = "((3+4)";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test28, 28) {
  std::string test_string = "sin(2";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test29, 29) {
  std::string test_string = "12+34+56+78+90+";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test30, 30) {
  std::string test_string = "3*4+5*6+7*8+";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test31, 31) {
  std::string test_string = "(1+2*(3+4))";
  std::string variable = "0";
  std::string expected_result = "15.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test32, 32) {
  std::string test_string = "sin(cos(tan(1)))";
  std::string variable = "0";
  std::string expected_result = "0.013388";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test33, 33) {
  std::string test_string = "log(log(log(log(log(log(2))))))";
  std::string variable = "0";
  std::string expected_result = "nan";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test34, 34) {
  std::string test_string = "sqrt(sqrt(sqrt(sqrt(sqrt(sqrt(4))))))";
  std::string variable = "0";
  std::string expected_result = "1.021897";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test35, 35) {
  std::string test_string =
      "1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+17+18+19+20+21+22+23+24+25+26+27+"
      "28+29+30+31+32+33+34+35+36+37+38+39+40+41+42+43+44+45+46+47+48+49+50+51+"
      "52+53+54+55+56+57+58+59+60+61+62+63+64+65+66+67+68+69+70+71+72+73+74+75+"
      "76+77+78+79+80+81+82+83+84+85+86+87+88+89+90+91+92+93+94+95+96+97+98+99+"
      "100+";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test36, 36) {
  std::string test_string =
      "1*2*3*4*5*6*7*8*9*10*11*12*13*14*15*16*17*18*19*20*21*22*23*24*25*26*27*"
      "28*29*30*31*32*33*34*35*36*37*38*39*40*41*42*43*44*45*46*47*48*49*50*51*"
      "52*53*54*55*56*57*58*59*60*61*62*63*64*65*66*67*68*69*70*71*72*73*74*75*"
      "76*77*78*79*80*81*82*83*84*85*86*87*88*89*90*91*92*93*94*95*96*97*98*99*"
      "100*";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test37, 37) {
  std::string test_string = "((1+2))";
  std::string variable = "0";
  std::string expected_result = "3.000000";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test38, 38) {
  std::string test_string = "(((((((((((((1))))))))))))))";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

TEST(test39, 39) {
  std::string test_string = "(((((((((((((1+2+3))))))))))))))";
  std::string variable = "0";
  std::string expected_result = "Invalid expression";
  model.SetExpression(test_string);
  model.SetVariable(variable);
  model.CalculateExpression();
  EXPECT_EQ(model.GetResult(), expected_result);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
