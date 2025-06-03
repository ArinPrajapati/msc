#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int n1 = m - 1;
    int n2 = n - 1;
    int c = m + n - 1;
    cout << n1 << " " << n2 << " " << c << endl;

    while (n1 >= 0 && n2 >= 0) {
      cout << n1 << " " << n2 << " " << c << endl;
      if (nums1[n1] > nums2[n2]) {
        nums1[c--] = nums1[n1--];
      } else {
        nums1[c--] = nums2[n2--];
      }
    }
    while (n2 >= 0) {
      nums1[c--] = nums2[n2--];
    }
  }
};

int main() {
  Solution solution;
  vector<int> nums1 = {4, 5, 6, 0, 0, 0};
  vector<int> nums2 = {1, 2, 3};
  int m = 3;
  int n = 3;

  solution.merge(nums1, m, nums2, n);

  for (int num : nums1) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
