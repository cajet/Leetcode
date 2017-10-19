class Solution {
public:
	int missingNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            if (nums[0] == 0) return 1;
            else return nums[0]-1;
        }
        sort(nums.begin(), nums.end());
		if (nums[0]!= 0) return 0;
        for (int i = 1; i < nums.size() ; i++) {
			if (nums[i] - nums[i - 1] == 1) continue;
			else {
				return nums[i - 1] + 1;
			}
		}
        return nums[nums.size()-1]+1;
	}
};