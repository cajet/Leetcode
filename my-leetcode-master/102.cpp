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
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int> > ans;
      if (root==NULL)
        return ans;

      TreeNode *cur;
      queue<TreeNode*> *s1=new queue<TreeNode*>(), *s2=new queue<TreeNode*>(), *s;
      s1->push(root);
      while (!s1->empty()) {
        vector<int> n;
        while (!s1->empty()) {
          cur = s1->front();
          s1->pop();
          n.push_back(cur->val);
          if (cur->left!=NULL)
            s2->push(cur->left);
          if (cur->right!=NULL)
            s2->push(cur->right);
        }
        ans.push_back(n);
        s = s1;
        s1 = s2;
        s2 = s;
      }

      return ans;
    }
};