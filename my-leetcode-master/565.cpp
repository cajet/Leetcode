class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.size() == 0|| nums.size() == 1) return nums.size();
		set<int> s;
		int max = 1, count;
		for (int i = 0; i < nums.size(); i++) {
			int temp = nums[i];
			count = 0;
			while (s.find(temp) == s.end()) {
				s.insert(temp);
				temp = nums[temp];
				count++;
			}
			if (count > max) max = count;
		}
		return max;
    }
};