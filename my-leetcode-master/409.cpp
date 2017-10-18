class Solution {
public:
	int longestPalindrome(string s) {
		if (s.length() == 0 || s.length() == 1) return s.length();
		map<char, int> m;
		for (int i = 0; i < s.length(); i++) {
			m[s[i]]++;
		}
		int count = 0;
		bool exit_odd = false;
		for (auto element : m) {
			if (element.second % 2 == 0) {
				count += element.second;
			}
			else {
				count += element.second - 1;
				exit_odd = true;
			}
		}
		if (exit_odd) return count + 1;
		else return count;
	}
};
