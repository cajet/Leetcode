class Solution {
public:
	int firstUniqChar(string s) {
		unordered_map<char, int> m;
		for (int i = 0; i < s.length(); i++) {
			m[s[i]]++;
		}
		char a;
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] == 1) return i;
		}
		return -1;
	}
};