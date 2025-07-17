#include <iostream>
#include<vector>
#include<queue>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int leveSize = q.size();
            vector<int> temp;

            for(int i = 0; i< leveSize;i++){
            TreeNode* tempNode = q.front();
            q.pop();


            temp.push_back(tempNode->val);
                
            if(tempNode->left != nullptr){
                q.push(tempNode->left);
            }

            if(tempNode->right != nullptr){
                q.push(tempNode->right);
            }
            }

            result.push_back(temp);

        }

        return result;
    }
};
