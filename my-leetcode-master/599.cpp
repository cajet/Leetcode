class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		map<string, int> m;
		map<int, vector<string>> mp;
		int min = INT_MAX;
		vector<string> v;
		for (int i = 0; i < list1.size(); i++) {
			m[list1[i]] = i+1;
		}
		for (int j = 0; j < list2.size(); j++) {
			if (m[list2[j]] != 0) {
				mp[m[list2[j]] + j - 1].push_back(list2[j]);
			}
		}
		map<int, vector<string>>::iterator it;
		it = mp.begin();
		return it->second;
	}
};