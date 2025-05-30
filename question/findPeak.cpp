#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
 public:
  int findPeakElement(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;


    while (l < r) { 
      int mid = l + (r - l) / 2;
      cout << mid << "  " << l << " " << " " << r << endl;

      if (nums[mid] > nums[mid + 1]) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};

int main() { 
  Solution sol;
  vector<int> nums = {1, 2, 3, 1};
  int peak = sol.findPeakElement(nums);
  cout << "Peak Element Index: " << peak << endl;
  return 0; 
};
