class Solution {  //有序版匹配
public:
	bool isSubsequence(string s, string t) {
		if (s.length() > t.length()) return false;
		if (s == "") return true;
		int i, j = 0;
		for (i = 0; i < s.length();) {
			for (; j < t.length(); j++) {
				if (s[i] == t[j]) {
					i++;
					j++;
					break;
				}
			}
			if (j == t.length() && i != s.length()) return false;
		}
		if (i == s.length()) return true;
		return false;
	}
};