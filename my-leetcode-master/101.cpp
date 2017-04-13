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
    inline bool isLeaf(TreeNode* node) {
      return node->right==NULL && node->left==NULL;
    }

    bool check(TreeNode *n1, TreeNode *n2) {
      if (n1==NULL&&n2==NULL)
        return true;
      if (n1==NULL||n2==NULL)
        return false;

      return n1->val==n2->val&&check(n1->left, n2->right)&&check(n1->right, n2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (root==NULL || isLeaf(root))
          return true;
        return check(root->left, root->right);
    }
};