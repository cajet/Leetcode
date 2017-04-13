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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      vector<vector<int> > ans;
      if (root==NULL)
        return ans;

      TreeNode *cur;
      queue<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
        int n = s.size();
        vector<int> node;
        while (n--) {
          cur = s.front();
          s.pop();
          node.push_back(cur->val);
          if (cur->left)
            s.push(cur->left);
          if (cur->right)
            s.push(cur->right);
        }
        ans.push_back(node);
      }

      reverse(ans.begin(), ans.end());
      return ans;    
    }
};


