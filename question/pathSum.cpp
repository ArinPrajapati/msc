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
  bool dfs(TreeNode *root, int targetSum, int crSum){

    if(root == nullptr){
      return false;
    }

    crSum += root->val;
    cout << crSum <<" " << root->val << endl;

    if(root->left == nullptr && root->right== nullptr){
      return crSum == targetSum;
    }
    return dfs(root->left, targetSum, crSum) || dfs(root->right, targetSum, crSum);
  }
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    int crSum = 0; 
    return dfs(root,targetSum,crSum); 
  }
};



int main(){
  // Example usage
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(4);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(11);
  root->left->left->left = new TreeNode(7);
  root->left->left->right = new TreeNode(2);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(4);
  root->right->right->right = new TreeNode(1);

  Solution sol;
  bool result = sol.hasPathSum(root, 22);

  cout << "Has path sum: " << (result ? "true" : "false") << std::endl;
  // Clean up memory (not shown)
 
  return 0;
}
