class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int minR = m;
		int minC = n;
		for (int i = 0; i < ops.size(); i++) {
			if (minR > ops[i][0]) minR = ops[i][0];
			if (minC > ops[i][1]) minC = ops[i][1];
		}
		return minR*minC;
	}
};