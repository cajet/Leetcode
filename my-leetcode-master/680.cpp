class Solution {
public:
	bool validPalindrome(string s) {
		return valid(s, 0, s.length()-1, 1);
	}
    bool valid(string& s, int i, int j, int d) { // d表示可以被删的个数
        if (i >= j) return true;
        if (s[i] == s[j])
            return valid(s, i + 1, j - 1, d);
        else
            return d > 0 && (valid(s, i + 1, j, d - 1) || valid(s, i, j - 1, d - 1));
    }
};