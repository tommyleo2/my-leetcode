/*
  You are a professional robber planning to rob houses along a street. Each
  house has a certain amount of money stashed, the only constraint stopping you
  from robbing each of them is that adjacent houses have security system
  connected and it will automatically contact the police if two adjacent houses
  were broken into on the same night.

  Given a list of non-negative integers representing the amount of money of each
  house, determine the maximum amount of money you can rob tonight without
  alerting the police.
 */

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    if (nums.size() == 1) {
      return nums.front();
    }
    if (nums.size() == 2) {
      return max(nums.front(), nums.back());
    }
    vector<int> r(nums.size() + 1);
    r[0] = 0;
    r[1] = nums[0];
    r[2] = max(nums[1], nums[0]);
    for (int i = 3; i < r.size(); i++) {
      r[i] = max(nums[i - 1] + r[i - 2], r[i - 1]);
    }
    return r.back();
  }
};

int main(void) {
  Solution s;

  return 0;
}
