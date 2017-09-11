/*
Given a string, your task is to count how many palindromic substrings in this
string.

The substrings with different start indexes or end indexes are counted as
different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.
*/

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int count = s.size();
    for (int i = 0; i < s.size() - 1; i++) {
      int left = i - 1;
      int right = i + 1;
      while (left >= 0 && right < s.size()) {
        if (s[left] == s[right]) {
          count++;
          left--;
          right++;
        } else {
          break;
        }
      }
      left = i;
      right = i + 1;
      while (left >= 0 && right < s.size()) {
        if (s[left] == s[right]) {
          count++;
          left--;
          right++;
        } else {
          break;
        }
      }
    }
    return count;
  }
};

int main() {
  cout << Solution().countSubstrings("bbb") << endl;
  return 0;
}
