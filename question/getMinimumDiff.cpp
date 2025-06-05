#include <algorithm>
#include <climits>
#include <cmath>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  void dfs(TreeNode *node, int minDiff, TreeNode *prev) {
    if (node == NULL) {
      return;
    }
    dfs(node->left, minDiff, prev);
    if (prev) {
      minDiff = min(minDiff, node->val - prev->val);
    }
    prev = node;
    dfs(node->right, minDiff, prev);
  };

public:
  int getMinimumDifference(TreeNode *root) {
    int minDiff = INT_MAX;
    TreeNode *prev;
    dfs(root,minDiff,prev);
    return minDiff;
  }
};

int main() { return 0; }
