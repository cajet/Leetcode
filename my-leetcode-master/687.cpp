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
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        int include_root = helper(root->left,root->val) + helper(root->right,root->val);
        return max(include_root, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }
    int helper(TreeNode* root, int val) {
        if(!root || root->val != val) return 0;
        return 1 + max(helper(root->left,val),helper(root->right,val));
    }
};