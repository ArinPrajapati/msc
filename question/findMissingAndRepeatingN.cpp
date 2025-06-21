#include <iostream>
#include <vector>

using namespace std;

vector<int> find(vector<int> nums) {
 int  n = nums.size();
  int s = n * (n + 1) / 2, s2 = n * ( n + 1) * ( 2* n + 1) / 6;

  int sum, sum2;

  for(int i = 0;i < n;i++){
    sum += nums[i];
    sum2 += nums[i] * nums[i];
  }

  int diff1 = sum - s;
  int diff2 = sum2 - s2;
  int sum_rm = diff2 / diff1;


  int r = (diff1 + sum_rm) / 2;
  int m = r - diff1;

 return {r,m};
}
