#include <cstddef>
#include <iostream>
#include <iterator>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;
  TreeNode() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  TreeNode *dfs(TreeNode *&node) {
    if (node == nullptr) {
      return nullptr;
    }

    TreeNode *leftTail = dfs(node->left);
    TreeNode *rightTail = dfs(node->right);

    if (leftTail != nullptr) {
      leftTail->right = node->right;
      node->right = node->left;
      node->left = nullptr;
    }

    return rightTail != nullptr  ? rightTail
           : leftTail != nullptr ? leftTail
                                 : node;
  }


public:
  void flatten(TreeNode *root) {
    dfs(root);
  }
};

int main() { return 0; }
