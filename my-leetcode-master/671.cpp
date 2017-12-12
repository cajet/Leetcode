class Solution {
public:
	void inorder(TreeNode* root, set<int>& s) {
		if (root->left) inorder(root->left, s);
		s.insert(root->val);
		if (root->right) inorder(root->right, s);
	}
	int findSecondMinimumValue(TreeNode* root) {
		set<int> s;
		inorder(root, s);
		if (s.size() <= 1) return -1;
		set<int> ::iterator it = s.begin();
		it++;
		return *it;
	}
};