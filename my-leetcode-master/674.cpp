class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int count = 1;
		for (int i = 1; i < nums.size(); ) {
			if (nums[i - 1] < nums[i]) {
				int temp = 1;
				while (i < nums.size() && nums[i - 1] < nums[i]) {
					temp++;
					i++;
				}
				if (temp > count) count = temp;
				continue;
			}
			i++;
		}
		return count;
	}
};