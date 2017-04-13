/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
      if (root==NULL)
        return;
      list<TreeLinkNode*> tmplist;
      tmplist.push_back(root);
      int size = 0;
      TreeLinkNode *tmp;

      while (!tmplist.empty()) {
        size = tmplist.size();
        for (int i = 0; i < size; i++) {
          tmp = tmplist.front();
          tmplist.pop_front();
          if (i != size-1)
            tmp->next = tmplist.front();
          if (tmp==NULL) continue;
          if (tmp->left!=NULL)
            tmplist.push_back(tmp->left);
          if (tmp->right!=NULL)
            tmplist.push_back(tmp->right);
        }
        tmp->next = NULL;
      }
    }
};