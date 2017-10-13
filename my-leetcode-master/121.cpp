class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1 || prices.size() == 0) return 0;
		int key, max = 0;
		for (int i = 0; i < prices.size()-1; i++) {
			key = prices[i];
			for (int j = i+1; j < prices.size(); j++) {
				if (key < prices[j] && max< prices[j]-key) {
					max = prices[j] - key;
				}
			}
		}
		return max;
	}
};