class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<vector<int>> v (m+1, vector<int>(n+1));
		for (auto str : strs) {
			int zero_sum = 0, one_sum = 0;
			for (int i = 0; i < str.length(); i++) {
				if (str[i] == '0') zero_sum++;
				else one_sum++;
			}
			for (int i = m; i >= zero_sum; i--) {
				for (int j = n; j >= one_sum; j--) {
					v[i][j] = max(v[i][j], 1 + v[i - zero_sum][j - one_sum]);
				}
			}
		}
		return v[m][n];
	}
};