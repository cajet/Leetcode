class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		vector<vector<int>> result(M);
		int row = M.size();
		int col = M[0].size();
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[0].size(); j++) {
				int sum = 0;
				int count = 0;
				for (int k = i - 1; k <= i + 1; k++) {
					for (int p = j - 1; p <= j + 1; p++) {
						if (k < 0 || p < 0 || k >= row || p >= col) continue;
						sum += M[k][p];
						count++;
					}
				}
				result[i][j] = sum / count;
			}
		}
		return result;
	}
};