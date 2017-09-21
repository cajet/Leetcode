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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2== NULL) return NULL;
        if (t1 == NULL && t2 != NULL) return t2;
        if (t1 != NULL && t2 == NULL) return t1;
        TreeNode *newTree= new TreeNode(t1->val + t2->val);
        newTree->left= mergeTrees(t1->left, t2->left);
        newTree->right= mergeTrees(t1->right, t2->right);
        return newTree;
    }
};