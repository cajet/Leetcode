struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void insert(TreeNode* &root, int val) {
      if (root==NULL) {
        root = new TreeNode(val);
      } else {
        TreeNode *cur=root, *parent;
        while(cur!=NULL) {
          parent = cur;
          if (val <cur->val)
            cur = cur->left;
          else
            cur = cur->right;
        }

        if (val<parent->val)
          parent->left = new TreeNode(val);
        else
          parent->right = new TreeNode(val);
      }
    }


    void findMid(ListNode *head, ListNode *end, TreeNode* &root) {
      if (head==end)
        return;

      ListNode *fast=head, *slow=head;
      while (fast->next!=end&&fast->next->next!=end) {
        fast = fast->next->next;
        slow = slow->next;
      }

      insert(root, slow->val);
      findMid(head, slow, root);
      findMid(slow->next, end, root);
    }


    TreeNode* sortedListToBST(ListNode* head) {
      TreeNode *root = NULL;
      findMid(head, NULL, root);
      return root;
    }
};
