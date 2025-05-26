#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int BthreeSumClosest(vector<int> &nums, int target) {

    size_t n = nums.size();

    if (n < 3) {
      return 0;
    }

    int cn = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {
      int pre = nums[i];
      int j = i + 1;
      int h = j + 1;

      while (j < n - 1) {
        int h = j + 1;
        while (h < n) {
          int temp = pre + nums[j] + nums[h];
          cout << nums[i] << " " << nums[j] << " " << nums[h] << " = " << temp
               << endl;

          if (abs(temp - target) < abs(cn - target)) {
            cn = temp;
          }
          h++;
        }
        j++;
      }
    }

    return cn;
  }

  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int cn = nums[1] + nums[2] + nums[0];

    for (int i = 0; i < nums.size() - 2; ++i) {
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[i] + nums[left] + nums[right];

        if (abs(sum - target) < abs(cn - target)) {
          cn = sum;
        }

        if (sum < target) {
          ++left;
        } else if (sum > target) {
          --right;
        } else {
          return target;
        }
      }
    }
    return cn;
  }
};

int main() {

  vector<int> v = {0, 3, 97, 102, 200};
  int target = 300;

  Solution s;
  int a = s.BthreeSumClosest(v, target);
  cout << a << endl;
}
