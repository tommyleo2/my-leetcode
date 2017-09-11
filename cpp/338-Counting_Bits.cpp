/*
  Given a non negative integer number num. For every numbers i in the range 0 ≤
i ≤ num calculate the number of 1's in their binary representation and return
them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like
__builtin_popcount in c++ or in any other language.
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.
*/

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  vector<int> countBits(int num) {
    if (num == 0) {
      return {0};
    }
    if (num == 1) {
      return {0, 1};
    }
    vector<int> result(num + 1);
    result[0] = 0;
    result[1] = 1;
    for (int i = 2; i <= num; i++) {
      if (i % 2 == 0) {
        result[i] = result[i / 2];
      } else {
        result[i] = result[i / 2] + 1;
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  for (auto i : s.countBits(100)) {
    cout << i << endl;
  }
  return 0;
}
