#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> nums, int n) {
  vector<vector<int>> result;
  result.push_back(nums[0]);

  for (int i = 1; i < n; i++) {
    int last = result.size() - 1;

    if (result[last][1] >= nums[i][0]) {
      result[last][1] = max(nums[i][1], result[last][1]);
    } else {
      result.push_back(nums[i]);
    }
  }
  return result;
}

int main() {

  vector<vector<int>> arr = {{2, 3}, {1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
  int n = arr.size();

  vector<vector<int>> merge = mergeIntervals(arr, n);
  for (auto &it : merge) {
    cout << " [";
    for (auto &i : it) {
      cout << i << ",";
    }
    cout << "]";
  }
}
