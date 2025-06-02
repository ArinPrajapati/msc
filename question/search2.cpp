#include <bits/stdc++.h>
#include <vector>

using namespace std;
class Solution {
private:
  int findPivot(vector<int> &nums) {
    int l = 0;
    int r = nums.size() - 1;

    if (nums[l] <= nums[r])
      return l;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if(mid < r && nums[mid] > nums[mid + 1]) return mid + 1;
      if(mid > l && nums[mid - 1] > nums[mid]) return mid;

      if(nums[mid] >= nums[l]){
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }
    return 0;
  };
  int binarySearch(vector<int>& nums,int target,int l ,int h){

    while(l <= h){
      int mid = l + (h - l)/2;

      if(nums[mid] == target){
        return mid;
      }
      else if(nums[mid] > target){
        h = mid -1;
      }else{
       l = mid +1 ;       
      }
    }
    return -1;
  }

public:
  int search(vector<int> &nums, int target) {
    int a = findPivot(nums);
    cout << a;
    return max(binarySearch(nums,target,0,a -1),binarySearch(nums,target,a,nums.size() -1 ));
  }
};

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  Solution sol;
  int result = sol.search(nums, target);
  cout << "Index of target " << target << " is: " << result << endl;

  return 0;
}
