/**
 * Given a string s, find the longest palindromic substring in s. You may assume
 that the maximum length of s is 1000.

 * Example:

 > Input: "babad"

 > Output: "bab"

  Note: "aba" is also a valid answer.
  Example:

 > Input: "cbbd"

 > Output: "bb"
*/

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) {
      return s;
    }
    auto ancher_start = s.begin();
    auto ancher_end = s.begin() + 1;

    auto stack_top = ancher_start;

    while (stack_top < s.end()) {
      uint trace = 1;
      //  even length size
      while (stack_top + trace < s.end() &&
             stack_top - trace + 1 >= s.begin() &&
             *(stack_top + trace) == *(stack_top - trace + 1)) {
        trace++;
      }
      if (2 * (trace - 1) > ancher_end - ancher_start) {
        ancher_start = stack_top - trace + 2;
        ancher_end = stack_top + trace;
      }
      //  odd length size
      trace = 1;
      while (stack_top + trace < s.end() && stack_top - trace >= s.begin() &&
             *(stack_top + trace) == *(stack_top - trace)) {
        trace++;
      }
      if (2 * trace - 1 > ancher_end - ancher_start) {
        ancher_start = stack_top - trace + 1;
        ancher_end = stack_top + trace;
      }
      stack_top++;
    }

    return string(ancher_start, ancher_end);
  }
};

int main(void) {
  string str;
  Solution s;
  cin >> str;
  cout << s.longestPalindrome(str) << endl;
  return 0;
}
