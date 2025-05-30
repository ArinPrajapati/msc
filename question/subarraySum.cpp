#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySumWrong(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> prefix(n, 0);
    int count = 0;

    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + nums[i];
    };

    int l = 0;
    int r = 0;

    while (r < n && l <= r) {
      int sum = 0;
      if (l == 0) {
        sum = prefix[r];
      } else {
        sum = prefix[r] - prefix[l-1];
      }

      cout << sum << endl;
      cout << l << endl;
      cout << r << endl;
      if (sum == k) {
        count++;
        r++;
      } else if (sum > k) {
        l++;
      } else {
        r++;
      }
    }
    return count;
  }

  int subarraySum(vector<int> &nums,int k){
    unordered_map<int,int> prefixCount;
    prefixCount[0] = 1;
    int prefixSum = 0, count = 0;

    for(int num:nums){
      prefixSum += num;
      count += prefixCount[prefixSum - k];
      prefixCount[prefixSum]++;
    }
    return count;
  }
};

int main() {
  Solution s;
  vector<int> v = {-1,-1,1};
  cout << s.subarraySum(v, 0);
  return 0;
}
