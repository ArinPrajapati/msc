#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void backtrack(vector<vector<int>> &result, vector<int> nums, int index) {
    if (index == nums.size()) {
      result.push_back(nums);
      return;
    }

    for (int i = index; i < nums.size(); i++) {
      swap(nums[index], nums[i]);
      backtrack(result, nums, index + 1);
      swap(nums[index], nums[i]);
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    int index = 0;
    backtrack(result, nums, index);
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> result = sol.permute(nums);
  for (const auto &perm : result) {
    for (int num : perm) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
