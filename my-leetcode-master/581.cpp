class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		vector<int> sorted_nums(nums);
		sort(sorted_nums.begin(), sorted_nums.end());
		int i, j;
		for (i = 0; i < sorted_nums.size(); i++) {
			if (sorted_nums[i] != nums[i]) break;
		}
		for (j = sorted_nums.size() - 1; j > 0; j--) {
			if (sorted_nums[j] != nums[j]) break;
		}
		if (i > j) return 0;
		else return j - i+1;
	}
};