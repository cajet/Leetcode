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
    int rob(TreeNode* root) {
      pair<int, int> ans = robSub(root);
      return max(ans.first, ans.second);
    }

    pair<int, int> robSub(TreeNode* root) {
      if (root==NULL)
        return pair<int, int>(0, 0);

      pair<int, int> ans;
      pair<int, int> left = robSub(root->left);
      pair<int, int> right = robSub(root->right);

      //不抢root
      ans.first = max(left.first, left.second)+max(right.first, right.second);
      //抢root
      ans.second = root->val+left.first+right.first;
      return ans;
    } 
};

