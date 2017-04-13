
#include<iostream>
#include<vector>
using namespace std;



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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      int size = nums.size();
      if (size==0)
        return NULL;
      int mid = (size-1)/2;
      TreeNode *root = new TreeNode(nums[mid]);
      bst(nums, 0, mid-1, root);
      bst(nums, mid+1, size-1, root);
      return root;
    }

    void bst(vector<int>& nums, int min, int max, TreeNode* root) {
      if (max >= nums.size() || min >= nums.size() || min > max)
        return;
      if (min == max) {
        insert(root, nums[min]);
      } else {
        int mid = min + (max-min)/2;
        insert(root, nums[mid]);
        bst(nums, min, mid-1, root);
        bst(nums, mid+1, max, root);
      }
    }

    void insert(TreeNode* root, int val) {
      TreeNode *cur = root;
      while (cur!=NULL) {
        if (val<cur->val) {
          if (cur->left==NULL) {
            cur->left = new TreeNode(val);
            break;
          }
          cur = cur->left;
        } else {
          if (cur->right==NULL) {
            cur->right = new TreeNode(val);
            break;
          }
          cur = cur->right;
        }
      }
    }
};


int main() {

}
