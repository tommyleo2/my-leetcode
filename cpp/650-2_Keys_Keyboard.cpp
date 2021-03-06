/*
Initially on a notepad only one character 'A' is present. You can perform two
operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy
is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the
minimum number of steps permitted. Output the minimum number of steps to get n
'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Note:
The n will be in the range [1, 1000].
*/

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  int minSteps(int n) {
    int step = 0;
    while (n > 1) {
      int i;
      int bound = std::sqrt(n);
      for (i = 2; i <= bound; i++) {
        if (n % i == 0) {
          break;
        }
      }
      if (i > bound) {
        step += n;
        break;
      }
      step += i;
      n /= i;
    }
    return step;
  }
};

int main() {
  cout << Solution().minSteps(99) << endl;
  return 0;
}
