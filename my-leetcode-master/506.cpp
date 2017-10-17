class Solution {
public:
	static int cmp(int x, int y) {
		return x > y;
	}
	vector<string> findRelativeRanks(vector<int>& nums) {
		vector<string> s;
		int bigger;
		for (int i = 0; i < nums.size(); i++) {
			bigger = 0;
			for (int j = 0; j < nums.size(); j++) {
				if (nums[i] < nums[j]) bigger++;
			}
			if (bigger == 0) s.push_back("Gold Medal");
			else if (bigger == 1) s.push_back("Silver Medal");
			else if (bigger == 2) s.push_back("Bronze Medal");
			else {
				string str;
				int temp = bigger + 1;
				stringstream ss;
				ss << temp;
				ss >> str;
				s.push_back(str);
			}
		}
		return s;
	}
};


//解法二：借助map
vector<string> findRelativeRanks(vector<int>& nums) {
	map<int, int> mp;
	map<int, int>::iterator it;
	for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
	vector<string> ans(mp.size());
	int cnt = nums.size();
	for (it = mp.begin(); it != mp.end(); it++) {
		if (cnt == 1) ans[it->second] = "Gold Medal";
		else if (cnt == 2) ans[it->second] = "Silver Medal";
		else if (cnt == 3) ans[it->second] = "Bronze Medal";
		else ans[it->second] = to_string(cnt);
		cnt--;
	}
	return ans;
}
