#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void backtrack(vector<vector<int>> &res, vector<int> &path,
                 vector<int> &candidates, int target, int count, int start) {
    if (count == target) {
      res.push_back(path);
      return;
    }
    if (count > target) {
      return;
    }

    for (int i = start; i < candidates.size(); ++i) {
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue; // Skip duplicates
      }
      path.push_back(candidates[i]);
      backtrack(res, path, candidates, target, count + candidates[i], i + 1);
      path.pop_back();
    }
  };

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(res, path, candidates, target, 0, 0);
    return res;
  }
};

int main() {
  Solution sol;
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> result = sol.combinationSum(candidates, target);
  for (const auto &combination : result) {
    cout << "[";
    for (const auto &num : combination) {
      cout << num << " ";
    }
    cout << "]" << endl;
  }
  return 0;
}
