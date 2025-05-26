#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLenIN(int target, vector<int> &nums) {
    int n = nums.size();

    vector<int> prefix(n + 1);
    prefix[0] = 0;
    int indexL = 0;
    int maxD = 0;

    if (nums[0] >= target) {
      return 1;
    }

    for (int i = 1; i < n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i];
      if (nums[i] >= target) {
        return 1;
      } else {
        if (nums[i] > maxD) {
          maxD = nums[i];
          indexL = i;
        }
      }
    }

    int left = indexL - 1;
    int right = indexL + 1;

    int countL = 2;
    int countR = 2;

    while (left > 0) {
      int sum = prefix[indexL] - prefix[left - 1];

      if (sum >= target) {
        return countL;
      }
      countL++;
      left--;
    }
    while (right < n) {
      int sum = prefix[right] - prefix[indexL - 1];
      if (sum >= target) {
        return countR;
      }
      countR++;
      right++;
    }

    return 0;
  }
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    int minLen = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int required = prefix[i] + target;

      int low = i + 1, high = n, pos = -1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (prefix[mid] >= required) {
          pos = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      if (pos != -1) {
        minLen = min(minLen, pos - i);
      }
    }
    return (minLen == INT_MAX) ? 0 : minLen;
  };


 int minSubArrayLenSW(int target,vector<int> &nums){
            int n = nums.size();
        int left = 0, sum = 0, minLen = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += nums[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }

        return minLen == INT_MAX ? 0 : minLen;

  }
};

int main() {
  Solution s;
  vector<int> n = {1, 2, 3, 4, 5};
  int t = 11;
  cout << s.minSubArrayLenSW(t, n);
  return 0;
}
