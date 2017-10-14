class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 1) return true;
		int i, j;
		for (i = 0; i < nums.size() - 1; i++) {
			if (nums[i] == 0) {
				for (j = 0; j < i; j++) {
					if (nums[j] >i - j) break;
				}
				if (j == i) return false;
			}
		}
		return true;
	}
};