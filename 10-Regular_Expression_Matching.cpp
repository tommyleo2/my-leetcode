/**
   Implement regular expression matching with support for '.' and '*'.

   '.' Matches any single character.
   '*' Matches zero or more of the preceding element.

   The matching should cover the entire input string (not partial).

   The function prototype should be:
   bool isMatch(const char *s, const char *p)

   Some examples:
   isMatch("aa","a") → false
   isMatch("aa","aa") → true
   isMatch("aaa","aa") → false
   isMatch("aa", "a*") → true
   isMatch("aa", ".*") → true
   isMatch("ab", ".*") → true
   isMatch("aab", "c*a*b") → true
 */

#include "headers.hpp"
#include <map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        if (p[1] == '*') {
            if (s.empty()) {
                return isMatch(s, p.substr(2, string::npos));
            }
            if (s[0] == p[0] || p[0] == '.') {
                return isMatch(s.substr(1, string::npos), p) || isMatch(s, p.substr(2, string::npos));
            }
            return isMatch(s, p.substr(2, string::npos));
        }
        if (s.empty()) {
            if (p[1] == '*') {
                return isMatch(s, p.substr(2, string::npos));
            }
            return false;
        }
        if (s[0] == p[0] || p[0] == '.') {
            return isMatch(s.substr(1, string::npos), p.substr(1, string::npos));
        }
        return false;
    }
};


int main(void) {
    Solution s;
    cout << boolalpha << (s.isMatch("aa", ".*..a*") == true) << endl;
    return 0;
}
