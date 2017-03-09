#include "headers.hpp"

using namespace std;

class Solution {
public:
  int reverse(int x) {
    if (x == -2147483648) return 0;
    if (!x) return 0;
     bool sign = x < 0;
     x = sign ? -x : x;

    int result = 0;

    int it = 0;
    while (x != 0) {
      if (it < 9) {
        result *= 10;
        result += x % 10;
      } else {
        int tmp = save_multi(result);
        if (tmp < 0) return 0;
        tmp = tmp + (x % 10);
        if (tmp < 0) return 0;
        result = tmp;
      }
      x /= 10;
      it++;
    }
    result = sign ? -result : result;

    return result;
  }

  int save_multi(int x) {
    int bitx = 0;
    while (x >> bitx && bitx < 32) {
      bitx++;
    }
    if (bitx <= 28) return x * 10;
    return -1;
  }

  int save_add(uint x, uint y) {
    int bitx = 0, bity = 0;
    while (x >> bitx) bitx++;
    while (y >> bity) bity++;
    if (bitx< 32 && bity < 32) return x + y;
    return -1;
  }

};


int main(void) {

  Solution s;
  int x;
  std::cin >> x;
  std::cout << s.reverse(x) << std::endl;
  return 0;
}
