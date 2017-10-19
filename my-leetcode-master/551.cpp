class Solution {
public:
	bool checkRecord(string s) {
		int count_A = 0, count_L = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'A') count_A++;
			else if (s[i] == 'L') {
				while (s[i] == 'L' && i< s.length()) {
					count_L++;
					i++;
				}
				if (count_L > 2) return false;
				else {
					count_L = 0;
				}
				i--;
			}
		 }
		if (count_A > 1) return false;
		else return true;
	}
};