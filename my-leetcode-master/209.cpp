	class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
            if (nums.size() == 0) return 0;
			int min = INT_MAX;
			for (int i = 0; i < nums.size(); i++) {
				int sum = nums[i];
				int count = 1;
				if (sum >= s) return 1;
				for (int j = i + 1; j < nums.size(); j++) {
					sum += nums[j];
					count++;
					if (sum >= s) {
						if (min > count) min = count;
						break;
					}
				}
			}
            if (min == INT_MAX) return 0;
			else return min;
		}
	};