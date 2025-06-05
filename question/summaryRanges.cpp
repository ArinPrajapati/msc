#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int> &nums) {
    vector<string> sen;
    int n = nums.size();
    if(n == 0){
      return sen;
    }
    int start = 0;
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] != nums[i] - 1) {
        if (start != i - 1) {
          sen.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));
        } else {
          sen.push_back(to_string(nums[start]));
        }
        start = i;
      }


    }

    if(start == n - 1){
      sen.push_back(to_string(nums[start]));
    }else{
      sen.push_back(to_string(nums[start]) + "->" + to_string(nums[n - 1]));
    }
    return sen;
  }
};
int main() {
  Solution s;
  vector<int> nums = {};
  vector<string> result = s.summaryRanges(nums);
  for (const string &range : result) {
    cout << range << " ";
  }
  return 0;

}
