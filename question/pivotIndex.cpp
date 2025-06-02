#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    vector<int> prefix(nums.size(), 0);
    prefix[0] = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      prefix[i] += prefix[i - 1]  + nums[i];
       
    };

    for (int i = 0; i < n; i++) {
      int prefixRight = i < n ? prefix[n -1] - prefix[i] : 0;
      int prefixLeft = i > 0 ? prefix[i - 1] : 0;

      cout << "i: " << i << ", prefixLeft: " << prefixLeft 
           << ", prefixRight: " << prefixRight << endl;
      if (prefixLeft == prefixRight) {
        return i;
      }
    }

    return -1;
  };
};

int main() { 
    
  Solution sol;
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  int result = sol.pivotIndex(nums);
  // Output the result
  cout << result;
  return 0; }
