#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    int n = nums.size();

    int l = 0;
    int r = 0;

    int ones = 0;
    int zeros = k;
    int maxSum = 0;

    while (r < n) {
     
      if (zeros < 0) {
        if (nums[l] == 0) {
          zeros++;
        } else {
          ones--;
        }
        l++;
      }
      if (nums[r] == 0) {
        zeros--;
      } else {
        ones++;
      }
       if (zeros >= 0) {
        maxSum = max(maxSum, ones + (k - zeros));
        cout << "l :" << l << " r : " << r << " k :" << k << " ones :" << ones << " zeros :" << zeros << endl;
      }
      r++;
    }
    return maxSum;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {0,0,0,4};
  int k = 4;
  int result = sol.longestOnes(nums, k);
  cout << "Longest subarray with at most " << k << " zeroes: " << result
       << endl;

  return 0;
}
