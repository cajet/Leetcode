/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<cmath>

class Solution {
public:
    inline bool isLeaf(TreeNode* node) {
      return node->right==NULL && node->left==NULL;
    }

    inline int max(int a, int b) {
      if (a>b)
        return a;
      else
        return b;
    }

    int depth(TreeNode* root) {
      if (root==NULL)
        return 0;
      return 1+max(depth(root->right), depth(root->left));
    }

    bool isBalanced(TreeNode* root) {
      if (root==NULL || isLeaf(root))
        return true;

      if (fabs(depth(root->right)-depth(root->left)) > 1)
        return false;

      return isBalanced(root->left)&&isBalanced(root->right);
    }
};