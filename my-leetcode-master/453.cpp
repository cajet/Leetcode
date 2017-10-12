class Solution {
public:
	int minMoves(vector<int>& nums) {
		int MIN = INT_MAX, sum = 0;
		for (int i = 0; i < nums.size(); i++) MIN = min(MIN, nums[i]);
		for (int j = 0; j < nums.size(); j++) sum += nums[j] - MIN;
		return sum;
	}
};