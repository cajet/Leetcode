class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.length() != t.length()) return false;
		if (s.length() == 1 || s.length() == 0) return true;
		unordered_map<char, char> m1, m2;
		for (int i = 0; i < s.length(); i++) {
			if (m1.find(s[i]) != m1.end()) {
				if (m1[s[i]] != t[i]) return false;
			}
			if(m2.find(t[i]) != m2.end()) {
				if (m2[t[i]] != s[i]) return false;
			}
			m1[s[i]] = t[i];
			m2[t[i]] = s[i];
		}
		return true;
	}
};