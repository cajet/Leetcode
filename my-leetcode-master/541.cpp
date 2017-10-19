class Solution {
public:
	string reverseStr(string s, int k) {
		if (k >= s.size()) {
			reverse(s.begin(), s.end());
			return s;
		}
		int count = s.length() / k;
		for (int i = 0; i <= count; i++) {
			if (i % 2 == 0) {
                if (i * k + k < s.length()) {
                    reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
		}
		return s;
	}
};


class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));
        }
        return s;
    }
};