class Solution {
public:
	string longestPalindrome(string s) {
        if (s.size() == 1) return s;
		int max = 0;
		int start;
		for (int i = 1; i < s.size(); i++) {
			//寻找以i-1,i为中点偶数长度的回文 
			int left = i - 1, right = i;
			while (left >= 0 && right < s.size() && s[left] == s[right]) {
				left--;
				right++;
			}
			if (max < right - left - 1) {
				max = right - left - 1;
				start = left + 1;
			}
			//寻找以i为中心的奇数长度的回文
			left = i - 1, right = i + 1;
			while (left >= 0 && right < s.size() && s[left] == s[right]) {
				left--;
				right++;
			}
			if (max < right - left - 1) {
				max = right - left - 1;
				start = left + 1;
			}
		}
		return s.substr(start, max);
	}
};
