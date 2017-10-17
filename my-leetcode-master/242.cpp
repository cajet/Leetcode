class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length()) return false;
		map<char, int> m;
		for (int i = 0; i < s.length(); i++) {
			m[s[i]]++;
		}
		for (int j = 0; j < t.length(); j++) {
			m[t[j]]--;
			if (m[t[j]] < 0) return false;
		}
		return true;
	}
};