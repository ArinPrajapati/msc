#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minOperations(vector<int> &nums) {

    int n = nums.size();
    int p = 0;
    int q = 2;
    int count = 0;

    while (q < n) {
      if (nums[p] != 1) {
        nums[p] = 1;
        nums[p + 1] = abs(nums[p + 1] - 1);
        nums[q] = abs(nums[q] - 1);
        count++;
      }

      if(q == (n-1)){
        if(nums[p+1] != 1 || nums[q] != 1){
          return -1;
        }
      }

      p++;
      q++;
    }

    return count;
  }
};

int main() { 
  Solution s;
  vector<int> n = {0,1,1,1,0,0};
  cout << s.minOperations(n);
  return 0;
}
