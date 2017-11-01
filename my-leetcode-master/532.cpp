class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
		int count = 0;
		if (nums.size() == 0 || nums.size() == 1) return 0;
		for (int i = 0; i < nums.size(); i++) {
			if ((i >= 1 && nums[i] != nums[i - 1]) || i== 0) {
				for (int j = i + 1; j < nums.size(); j++) {
					if (nums[j] - nums[i] == k) {
						count++;
						break;
					}
				}
			}
		}
        return count;
	}
};