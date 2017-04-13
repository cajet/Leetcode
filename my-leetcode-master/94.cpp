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
    void Inorder(TreeNode* root, vector<int>& ans) {
      if (root == NULL)
        return;
      Inorder(root->left, ans);
      ans.push_back(root->val);
      Inorder(root->right, ans);
    }

    //使用函数栈的递归
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> ans;
      Inorder(root, ans);
      return ans;
    }

    //使用数据结构栈的模拟递归
    vector<int> inorderTraversal1(TreeNode* root) {
      TreeNode* cur = root;
      vector<int> ans;
      stack<TreeNode*> parent;

      while (!parent.empty() || cur!=NULL) {
        while (cur!=NULL) {
          parent.push(cur);
          cur = cur->left;
        }

        cur = parent.top();
        parent.pop();
        
        ans.push_back(cur->val);
        cur = cur->right;
      }
      return ans;
    }

    //Morris 遍历，会破坏原本树的结构，把原来的书变成右偏的线性树
    vector<int> inorderTraversal2(TreeNode* root) {}
};
