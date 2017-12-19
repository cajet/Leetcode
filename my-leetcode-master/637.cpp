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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			long sum = 0;
			int count = q.size();
			for (int i = 0; i < count; i++) {
				TreeNode* temp = q.front();
				q.pop();
				if (temp->left) {
					q.push(temp->left);
				}
				if (temp->right) {
					q.push(temp->right);
				}
				sum += temp->val;
			}
			res.push_back((sum+0.0) / count);
		}
		return res;
	}
};