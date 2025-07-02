#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      for (int j = i + 1; j < nums.size(); j++) {
        if (j > i + 1 && nums[j] == nums[j - 1])
          continue;

        int left = j + 1;
        int right = nums.size() - 1;

        while (left < right) {
          long long tsum =
              (long long)nums[i] + nums[j] + nums[left] + nums[right];
          if (target == tsum) {
            vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
            while (left < right && nums[left] == nums[left + 1])
              left++;
            while (left < right && nums[right] == nums[right - 1])
              right--;
            result.push_back(temp);

            left++;
            right--;
          } else if (target < tsum) {
            right--;
          } else {
            left++;
          }
        }
      }
    }
    return result;
  };

  vector<vector<int>> fourSum1(vector<int> &nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for(int i = 0;i < nums.size() - 3;++i){ 
      if(i > 0 && nums[i] == nums[i-1]){
        continue;
      }
      for(int j = i + 1;j < nums.size() - 2;++j){
        if(j > i + 1 && nums[j] == nums[j - 1]){
          continue;
        }
        int left = j + 1;
        int right = nums.size() - 1;

        while(left < right){
          long long tsum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
          if(target == tsum){
            vector<int> temp = {nums[i] , nums[j] , nums[left], nums[right]};
            result.push_back(temp);
            while(left < right && nums[left] == nums[left+1]){
              left++;
            }
            while(left < right && nums[right] == nums[right - 1]){
              right--;
            } 
            left++;
            right--;
          }else if(tsum < target){
            left++;
          }else{
            right--;
          }
        }
      }
    }
    return result;
  };
};



int main(){
  Solution sol;
  vector<int> nums = {1, 0, -1, 0, -2, 2};
  int target = 0;
  vector<vector<int>> result = sol.fourSum1(nums, target);

  for (const auto &vec : result) {
    cout << "[";
    for (int num : vec) {
      cout << num << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}
