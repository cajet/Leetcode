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
    /*当root的值位于L和R之间，则递归修剪其左右子树，返回root。
    当root的值小于L，则其左子树的值都小于L，抛弃左子树，返回修剪过的右子树。
    当root的值大于R，则其右子树的值都大于R，抛弃右子树，返回修剪过的左子树。*/
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;
        if (root->val< L) return trimBST(root->right, L, R);
        else if (root->val> R) return trimBST(root->left, L, R);
        else {
            root->left= trimBST(root->left, L, R);
            root->right= trimBST(root->right, L, R);
        }
        return root;
    }
};