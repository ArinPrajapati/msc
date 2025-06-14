#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

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

public:
  vector<double> averageOfLevels(TreeNode *root) {
    int prevCo = 1;
    vector<double> i;
    queue<TreeNode *> q;
    q.push(root);

    while (q.size() > 0) {

      int levelSize = q.size();
      double sum = 0;

      for (int i = 0; i < levelSize; ++i) {
        TreeNode *curr = q.front();
        q.pop();

        sum += curr->val;

        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }

      i.push_back(sum / levelSize);
    }

    return i;
  }
};

int main() { return 0; }
