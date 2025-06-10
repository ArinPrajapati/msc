#include <algorithm>
#include <climits>
#include <iostream>

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
  int finder(TreeNode* node,int &maxi){
    if(node == nullptr){
      return 0;
    }

    int leftSum = max(0,finder(node->left,maxi));
    int rightSum = max(0,finder(node->right,maxi));

    maxi = max(maxi,leftSum + rightSum + node->val);
    return max(leftSum,rightSum) + node->val;
  };
public:
  int maxPathSum(TreeNode *root) {
    int maxi = INT_MIN;
    finder(root,maxi);
    return maxi;
  }
};

int main(){
  // Example usage:
  TreeNode *root = new TreeNode(-10);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));

  Solution sol;
  cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl; // Output: 42

  // Clean up memory (not shown)
  return 0;
}

