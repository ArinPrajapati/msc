#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
private:
  int binarySearch(vector<int> nums, int target, bool leftbias) {
    int r = nums.size() - 1;
    int l = 0;

    int i = -1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (target > nums[m])
        l = m + 1;
      else if (target < nums[m])
        r = m - 1;
      else {
        i = m;
        if (leftbias)
          r = m - 1;
        else
          l = m + 1;
      }
    }
   return i;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> result(2, 0);
    result[0] = binarySearch(nums, target, true);
    result[1] = binarySearch(nums, target, false);

    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> result = s.searchRange(nums, target);
  cout << "First and last position of target " << target << " are: "
       << result[0] << " and " << result[1] << endl;
  return 0; 
}
