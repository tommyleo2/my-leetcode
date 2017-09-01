/*
  Given an integer, convert it to a roman numeral.
  Input is guaranteed to be within the range from 1 to 3999.
*/

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  Solution()
      : mapper({{1, "I"},
                {4, "IV"},
                {5, "V"},
                {9, "IX"},
                {10, "X"},
                {40, "XL"},
                {50, "L"},
                {90, "XC"},
                {100, "C"},
                {400, "CD"},
                {500, "D"},
                {900, "CM"},
                {1000, "M"}}) {}
  string intToRoman(int num) {
    string result;
    if (num >= 1000) {
      int thousand = num / 1000;
      while (thousand--) {
        result += mapper[1000];
      }
      num %= 1000;
    }

    int it = 100;

    int major = num / it;
    int minor = num % it;

    while (it) {
      major = num / it;
      minor = num % it;

      if (major == 4 || major == 9) {
        result += mapper[major * it];
        it /= 10;
        num = minor;
        continue;
      }

      if (major >= 5) {
        result += mapper[5 * it];
        major -= 5;
      }

      while (major--) {
        result += mapper[it];
      }

      it /= 10;
      num = minor;
    }

    return result;
  }

  map<int, string> mapper;
};

int main() {
  Solution s;
  cout << s.intToRoman(41) << endl;
  return 0;
}
