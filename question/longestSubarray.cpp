#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int ones = 0;
    int zeros = 1;

    int l = 0;
    int r = 0;

    int n = nums.size();

    int maxSum = 0;
    while (r < n) {
      if (zeros == 0 && nums[r] == 0) {
        maxSum = max(maxSum, ones);
        if (nums[l] == 0) {
          zeros++;
        } else {
          ones--;
        }
        l++;
      } else {
        if (nums[r] == 0) {
          zeros--;
        } else {
          ones++;
        }
        r++;
      }
    }
    maxSum = max(maxSum,ones);
    return (maxSum == n ? maxSum - 1: maxSum);
  }
};

int main() {
  Solution sol;

  vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
  int result = sol.longestSubarray(nums);
  cout << "Longest subarray length: " << result << endl;
  return 0;
}
