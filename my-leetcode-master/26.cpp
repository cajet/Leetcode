class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		set<int> s;
		for (int i = 0; i < nums.size(); i++) {
			s.insert(nums[i]);
		}
		nums.resize(s.size());
		set<int>::iterator it;
		int i;
		for (i = 0, it= s.begin(); i < nums.size(); i++, it++) {
			nums[i] = *it;
		}
		return s.size();
	}
};