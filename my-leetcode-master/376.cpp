class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int flag = 0;   //0为初始状态，1表示升序，2表示降序
		int count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1] && (flag == 0 || flag == 2)) {
				flag = 1;
				count++;
			}
			else if (nums[i] < nums[i - 1] && (flag == 0 || flag == 1)) {
				flag = 2;
				count++;
			}
		}
		return count;
	}
};