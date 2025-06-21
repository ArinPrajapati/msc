#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int countWithXorValue(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    int prefixXor = 0;
    int count = 0;

    for (int num : nums) {
      prefixXor ^= num;
      if (prefixXor == k) {
        count++;
      }
      if (freq.find(prefixXor ^ k) != freq.end()) {
        count += freq[prefixXor ^ k];
      }

      freq[prefixXor]++;
    }
    return count;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 3;

  int result = solution.countWithXorValue(nums, k);
  cout << "Count of subarrays with XOR equal to " << k << ": " << result
       << endl; // output: Count of subarrays with XOR equal to 3: 2  

  return 0;
}
