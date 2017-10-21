class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		map<int, int > m;
		vector<int> v;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]]++;
		}
		for (auto element : m) {
			if (element.second == 2) {
				v.push_back(element.first);
				for (int i = 1; i <= nums.size(); i++) {
					if (m[i] == 0) v.push_back(i);
				}
				break;
			}
		}
		return v;
	}
};