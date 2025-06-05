#include <climits>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    int maxSum = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++) {

       sum +=  nums[i];
      maxSum = max(maxSum,sum);
      if(sum < 0){
        sum = 0;
        cout << endl;
      }else{
        cout << nums[i] << " "; 
      }
    }
    return maxSum;
  }
};

int main() {
  
  Solution solution;
  vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
  int result = solution.maxSubArray(nums);
  cout << "Maximum subarray sum is: " << result << endl;

  return 0;
}
