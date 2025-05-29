#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
      int mid = low +(high - low) / 2;
       cout << "mid: " << mid << ", nums[mid]: " << nums[mid] << endl;

      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return low;
  }
};

int main() { 
  Solution s;
  vector<int> d = {1,3,5,6};
  cout << s.searchInsert(d,6);
  return 0;
}
