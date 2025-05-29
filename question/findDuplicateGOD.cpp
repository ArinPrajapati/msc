#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int s = 0;
    int f = 0;

    do {
      s = nums[s];
      f = nums[nums[f]];
    } while (s != f);

    s = 0;

    while (s != f) {
      s = nums[s];
      f = nums[f];
    }

    return s;
  }
};

int main() {
  vector<int> n = {1, 3, 4, 2, 2};
  Solution s;
  cout << s.findDuplicate(n);
  return 0;
}
