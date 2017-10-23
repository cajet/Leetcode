class Solution {
public:
	bool isvowels(char c) {
		char a = tolower(c);
		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
		else return false;
	}
	string reverseVowels(string s) {
		if (s.length() == 1 || s.length() ==0) return s;
		int i, j;
		for (i = 0, j = s.size(); i < j; ) {
			if (isvowels(s[i]) && isvowels(s[j])) {
				int temp = s[i];
				s[i] = s[j];
				s[j] = temp;
				i++;
				j--;
			}
			else if (isvowels(s[i])) {
				j--;
			}
			else if (isvowels(s[j])){
				i++;
			}
			else {
				i++;
				j--;
			}
		}
		return s;
	}
};