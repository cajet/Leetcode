class Solution {
public:
	static int cmp(vector<int> x, vector<int> y) {
		return x[1] < y[1];
	}
	int findLongestChain(vector<vector<int>>& pairs) {
		if (pairs.size() == 1||pairs.size() ==0) return pairs.size();
		sort(pairs.begin(), pairs.end(), cmp);
		int count = 1, first = pairs[0][1];
		for (int i = 1; i < pairs.size(); i++) {
			if (pairs[i][0] > first) {
				count++;
				first = pairs[i][1];
			}
		}
		return count;
	}
};