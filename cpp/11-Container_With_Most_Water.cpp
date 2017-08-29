/*
  Given n non-negative integers a1, a2, ..., an, where each represents a point
  at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
  of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
  forms a container, such that the container contains the most water.

  Note: You may not slant the container and n is at least 2.
 */

#include "headers.hpp"

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    data = &height;
    left = 0;
    right = height.size() - 1;
    max = 0;

    checkAreaAndMove();

    while (left != right) {
      checkAreaAndMove();
    }
    return max;
  }

 private:
  int area() {
    return (right - left) * std::min(data->at(left), data->at(right));
  }
  void checkAreaAndMove() {
    int tmp_area = area();
    if (tmp_area > max) {
      max = tmp_area;
    }
    if (data->at(left) < data->at(right)) {
      left++;
    } else {
      right--;
    }
  }

  vector<int>* data;
  int left, right;
  int max;
};

int main(void) {
  Solution s;
  vector<int> a{1, 1};
  cout << s.maxArea(a) << endl;
  return 0;
}
