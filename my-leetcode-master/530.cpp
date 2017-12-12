class Solution {
public:
	void inorder(TreeNode* root, int& MIN, int& pre) {
		if (root->left) inorder(root->left, MIN, pre);
		if (pre != -1) MIN = min(MIN, root->val - pre);
        pre= root->val;
		if (root->right) inorder(root->right, MIN, pre);
	}
	int getMinimumDifference(TreeNode* root) {
		int pre = -1, MIN = INT_MAX;
		inorder(root, MIN, pre);
		return MIN;
	}
};