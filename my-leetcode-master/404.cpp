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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode* cur = nodes.front();
            nodes.pop();
            if (cur->left) {
                if (!(cur->left)->left && !(cur->left)->right) sum += (cur->left)->val;
                else nodes.push(cur->left);
            }
            if (cur->right) nodes.push(cur->right);
        }
        return sum;
    }
};