class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int> v;
		for (int i = 0; i < findNums.size(); i++) {
			int k;
			for (k = 0; k < nums.size(); k++) {
				if (findNums[i] == nums[k]) {
					break;
				}
			}
			int j;
			for (j = k+1; j < nums.size(); j++) {
				if (nums[j] > findNums[i]) {
					v.push_back(nums[j]);
					break;
				}
			}
			if (j == nums.size()) v.push_back(-1);
		}
		return v;
	}
};