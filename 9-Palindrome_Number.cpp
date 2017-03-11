/**
   Determine whether an integer is a palindrome. Do this without extra space.

   Some hints:
   Could negative integers be palindromes? (ie, -1)

   If you are thinking of converting the integer to string, note the restriction of using extra space.

   You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

   There is a more generic way of solving this problem.


 */

#include "headers.hpp"

class Solution {
  int getDigit(int x, int i) {
    i--;
    while (i) {
      x /= 10;
      i--;
    }
    return x % 10;
  }
public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    if (x % 10 == 0) return false;

    int digit = 0;
    int tmp_x = x;
    while (tmp_x) {
      tmp_x /= 10;
      digit++;
    }
    int it = digit / 2;
    while (it) {
      if (getDigit(x, it) != getDigit(x, digit - it + 1)) return false;
        it--;
    }
    return true;
  }
};

using namespace std;


int main(void) {
  Solution s;
  cout << s.isPalindrome(1410110141) << endl;;
  return 0;
}
