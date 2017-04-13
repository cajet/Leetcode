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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n==0)
            return result;
      return fun(1, n);
    }

    vector<TreeNode*> fun(int from, int to) {
      vector<TreeNode*> result;
      if (to < from)  
        result.push_back(NULL);
      else if (to == from) { 
        result.push_back(new TreeNode(to));
      } else {
        for (int i = from; i <= to; i++) {
          vector<TreeNode*> l = fun(from, i-1);
          vector<TreeNode*> r = fun(i+1, to);

          for (int j = 0; j < l.size(); j++) {
            for (int k = 0; k < r.size(); k++) {
              TreeNode *node = new TreeNode(i);
              node->left = l[j];
              node->right = r[k];
              result.push_back(node);
            }
          }
        }
      }

      return result;
    }
};
