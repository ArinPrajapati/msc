#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
      vector<int> temp = matrix[i];

      int l = 0;
      int r = m - 1;

      while (l <= r) {
        int mid = (l + (r - l)) / 2;

        if (temp[mid] == target) {
          return true;
        } else if (temp[mid] > target) {
          r = mid - 1;
        } else {
          l = mid+1;
        }
      }
    }

    return false;
  }
};
