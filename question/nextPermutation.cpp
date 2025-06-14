#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int point = -1;

    for (int i = nums.size() - 1; i >= 1; i--) {
      if (nums[i - 1] < nums[i]) {
        point = i - 1;
      }
    }

    if (point != -1) {
      if (point != -1) {
        for (int i = nums.size() - 1; i > point; i--) {
          if (nums[i] > nums[point]) {
            swap(nums[i], nums[point]);
            break;
          }
        }
      }
    } else {
      cout << "point: " << point << endl;
      reverse(nums.begin() + point + 1, nums.end());
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {3,2,1};
  s.nextPermutation(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  return 0;
}
