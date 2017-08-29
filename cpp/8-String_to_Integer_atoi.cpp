/**
   Implement atoi to convert a string to an integer.

   Hint: Carefully consider all possible input cases. If you want a challenge,
   please do not see below and ask yourself what are the possible input cases.

   Notes: It is intended for this problem to be specified vaguely (ie, no given
   input specs). You are responsible to gather all the input requirements up
   front.

   Requirements for atoi:
   The function first discards as many whitespace characters as necessary until
   the first non-whitespace character is found. Then, starting from this
   character, takes an optional initial plus or minus sign followed by as many
   numerical digits as possible, and interprets them as a numerical value.

   The string can contain additional characters after those that form the
   integral number, which are ignored and have no effect on the behavior of this
   function.

   If the first sequence of non-whitespace characters in str is not a valid
   integral number, or if no such sequence exists because either str is empty or
   it contains only whitespace characters, no conversion is performed.

   If no valid conversion could be performed, a zero value is returned. If the
   correct value is out of the range of representable values, INT_MAX
   (2147483647) or INT_MIN (-2147483648) is returned.
 */

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    if (str.empty()) {
      return 0;
    }
    int sign = 1;
    int pos = 0;
    long long result = 0;
    while (str[pos] == ' ') {
      pos++;
    }
    if (str[pos] == '-') {
      if (str.substr(pos, sizeof("-2147483648")) == "-2147483648") {
        return -2147483648;
      }
      sign = -1;
      pos++;
    } else if (str[pos] == '+') {
      pos++;
      if (str.substr(pos, sizeof("2147483647")) == "2147483647") {
        return 2147483647;
      }
    }

    for (; pos < str.size(); pos++) {
      if (str[pos] >= '0' && str[pos] <= '9') {
        result *= 10;
        result += str[pos] - '0';
        if (result > 2147483647) {
          if (sign == 1) return 2147483647;
          return -2147483648;
        }
      } else {
        break;
      }
    }
    return result * sign;
  }
};

int main(void) {
  Solution s;
  int result = 100;
  // cout << result << " " << (s.myAtoi("100") == result) << endl;

  // result = -100;
  // cout << result << " " << (s.myAtoi("-100") == result) << endl;

  result = 2147483647;
  cout << result << " " << (s.myAtoi("    10522545459")) << endl;

  // cout << atoi("-2147483648") << endl;
  return 0;
}
