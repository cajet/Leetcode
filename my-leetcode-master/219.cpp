class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		map<int, int > m;
		for (int i = 0; i < nums.size(); i++) {
			if (m[nums[i]] != 0 && k >= i + 1 - m[nums[i]]) return true;
			m[nums[i]] = i+1;
		}
		return false;
	}
};