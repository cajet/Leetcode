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
	void inorder(vector<int> &v, TreeNode* root) {
		if (root == NULL) return;
		inorder(v, root->left);
		v.push_back(root->val);
		inorder(v, root->right);
	}
	bool findTarget(TreeNode* root, int k) {
		vector<int> v;
		inorder(v, root);
		int i, j;
		for (i = 0, j = v.size() - 1; i < j;) {
			if (v[i] + v[j] == k) return true;
			else  if (v[i] + v[j] < k) i++;
			else j--;
		}
        return false;
	}
};