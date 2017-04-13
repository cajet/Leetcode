/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    inline bool isLeaf(TreeNode* root) {
      return root->right==NULL&&root->left==NULL;
    }

    bool hasPathSum(TreeNode* root, int sum) {
      if (root==NULL)
        return false;

      int ans = root->val;
      if (isLeaf(root))
        return ans==sum;
      
      return hasPathSum(root->right, sum-ans) || hasPathSum(root->left, sum-ans);
    }
};