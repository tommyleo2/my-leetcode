#include "headers.hpp"

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> result;
  map<int, int> numMap;
  for (int i = 0; i < nums.size(); i++) {
    auto iter = numMap.find(target - nums[i]);
    if (iter != numMap.end()) {
      result.push_back(iter->second);
      result.push_back(i);
      return result;
    }
    numMap.insert(pair<int, int>(nums[i], i));
  }
  return result;
}

int main(void) {
  // map<int, int> test;
  // test.insert(pair<int, int>(1, 100));
  // test.insert(pair<int, int>(2, 200));
  // auto iter = test.find(2) ;
  // if (iter != test.end()) {
  //     cout << iter->first << " " << iter->second << endl;
  // }
  // return 0;

  vector<int> list{3, 2, 4};
  auto result = twoSum(list, 6);
  cout << result[0] << " " << result[1] << endl;
  return 0;
}
