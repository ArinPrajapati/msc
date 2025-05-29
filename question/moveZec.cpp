#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int l = 0;
    int r = 1;

    int n = nums.size();
    while (r < n) {
      if (nums[l] == 0 && nums[r] != 0) {
        int temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;
        r = l +1;
      }
      if (nums[l] > 0) {
        l++;
        r = l + 1;
      }
      r++;
    }
  }
};

int main() {
  Solution s;
  vector<int> v = {0, 1};
  s.moveZeroes(v);

  for (int s : v) {
    cout << s << " ";
  }
  return 0;
}
