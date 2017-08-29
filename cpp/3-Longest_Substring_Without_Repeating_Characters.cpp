/**
 *  Given a string, find the length of the longest substring without repeating
 characters.

 *  Examples:

 *  Given "abcabcbb", the answer is "abc", which the length is 3.

 *  Given "bbbbb", the answer is "b", with the length of 1.

 *  Given "pwwkew", the answer is "wke", with the length of 3. Note that the
 answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    auto start_position = s.begin();
    auto current_position = s.begin();
    int length = 0, current_length = 0;

    for (auto it = s.begin(); it != s.end(); it++) {
      auto pos = find(current_position, current_position + current_length, *it);
      if (pos == current_position + current_length) {
        current_length++;
        continue;
      } else {
        if (current_length > length) {
          start_position = current_position;
          length = current_length;
        }
        current_length = it - pos;
        current_position = pos + 1;
      }
    }
    if (current_length > length) {
      return current_length;
    }
    return length;
  }
};

int main() {
  string s;
  Solution sol;
  cin >> s;
  cout << sol.lengthOfLongestSubstring(s) << endl;
  return 0;
}
