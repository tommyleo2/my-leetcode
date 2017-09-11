/*
Given an unsorted array of integers, find the number of longest increasing
subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 2
Explanation:
The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: [2,2,2,2,2]
Output: 5
Explanation:
The length of longest continuous increasing subsequence is 1, and there are 5
subsequences' length is 1, so output 5.

Note: Length of the given array will be not exceed 2000 and the answer is
guaranteed to be fit in 32-bit signed int.
*/

#include "headers.hpp"

using namespace std;

class Solution {
  struct Record {
    int length;
    int num;
  };

 public:
  int findNumberOfLIS(const vector<int> &nums) {
    if (nums.size() == 1) {
      return 1;
    }
    vector<Record> records(nums.size(), {1, 1});
    for (int i = 1; i < records.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (records[j].length + 1 > records[i].length) {
            records[i].length = records[j].length + 1;
            records[i].num = records[j].num;
          } else if (records[j].length + 1 == records[i].length) {
            records[i].length = records[j].length + 1;
            records[i].num += records[j].num;
          }
        }
      }
    }
    Record max{0, 0};
    for (auto &&record : records) {
      if (record.length > max.length) {
        max = record;
      } else if (record.length == max.length) {
        max.num += record.num;
      }
    }
    return max.num;
  }
};

int main() {
  cout << Solution().findNumberOfLIS({2, 2, 2, 2, 2, 2}) << endl;
  return 0;
}
