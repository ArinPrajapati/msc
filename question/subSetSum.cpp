#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool bruteForce(vector<int> nums, int sum, int index, int target) {

  if (sum == target) {
    cout << index << " " << sum << endl;
    return true;
  }
  if (index == nums.size()) {
    return false;
  }

  bool step1 = bruteForce(nums, sum + nums[index], index + 1, target);
  bool step2 = bruteForce(nums, sum, index + 1, target);
  return step1 || step2;
};

bool dpMemo(vector<int> &nums, int sum, int index, int target,
            vector<vector<int>> &dp) {
  if (sum == target) {
    return true;
  }

  if (index == nums.size()) {
    return false;
  }

  if (dp[index][sum] != -1) {
    return dp[index][sum];
  }

  bool step1 = false;
  if (sum + nums[index] <= target) {
    step1 = dpMemo(nums, sum + nums[index], index + 1, target, dp);
  }
  bool step2 = dpMemo(nums, sum, index + 1, target, dp);

  return dp[index][sum] = step1 || step2;
};

int main() {
  vector<int> nums = {1, 2, 3, 4, 5};
  int target = 9;
  vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

  if (dpMemo(nums, 0, 0, target, dp)) {
    cout << "Subset with sum " << target << " exists." << endl;
  } else {
    cout << "Subset with sum " << target << " does not exist." << endl;
  }
  return 0;
}
