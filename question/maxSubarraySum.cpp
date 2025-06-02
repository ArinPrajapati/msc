#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int maxSum = 0;

    int n = nums.size();
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];

    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    }

    int l = 0;
    int r = 0;

    while (r < n) {
      int len  = r - l;
      if(len % k == 0){
        int sum  = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
        maxSum= max(maxSum,sum);
        l++;
        r++;
      }else{
        r++;
      }
    }
    return maxSum;
  }
};

int main() {
  Solution s;
  vector<int> nums = {-5,1,2,-3,4};
  int c = s.maxSubarraySum(nums, 1);
  cout << c;
  return 0;
}
