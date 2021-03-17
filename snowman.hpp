#include <iostream>
#include <string>
#include <array>

const int MAX_INPUT = 44444444, MIN_INPUT = 11111111, MIN_CHAR = 1, MAX_CHAR = 4, DIVIDER = 10;
const int H = 1, N = 2, L = 3, R = 4, X = 5, Y = 6, T = 7, B = 8;

namespace ariel
{
      std::string snowman(int input);
      bool check_isvalid(int input);
      std::string buildSnowman(int input);
};