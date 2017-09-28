/*哈希表 O(n)*/
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(nums[i]) == m.end()) m[nums[i]] = 0;
			else m[nums[i]] ++;
			if (m[nums[i]] > nums.size() / 2) return nums[i];
		}
	}
};

/*Majority Element*/
/*分治 O(nlogn)*/
class Solution {
public:
	int helper(vector<int>& nums, int left, int right) {
		if (left == right) return nums[left];
		int mid = (left + right) / 2;
		int leftMajor = helper(nums, left, mid);
		int rightMajor = helper(nums, mid + 1, right);
		if (leftMajor == rightMajor) return leftMajor;
		int leftcount = 0, rightcount = 0;
		for (int i = left; i <= right; i++) {
			if (nums[i] == leftMajor) leftcount++;
			else if (nums[i] == rightMajor) rightcount++;
		}
		return leftcount > rightcount ? leftMajor : rightMajor;
	}
	int majorityElement(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};