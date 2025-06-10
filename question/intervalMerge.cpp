#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();

    vector<int> cur = intervals[0];
    for (int i = 1; i < n; i++) {
      int start = intervals[i][0];
      int end = intervals[i][1];

      if (cur[1] >= start) {
        cur[0] = min(start,cur[0]);
        cur[1] = max(end, cur[1]);
      } else {
        ans.push_back(cur);
        cur[0] = start;
        cur[1] = end;
      }
    }
    ans.push_back(cur);
    return ans;
  }
};

int main() { return 0; }
