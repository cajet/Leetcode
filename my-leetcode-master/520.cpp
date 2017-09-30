class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.length() == 1) return true;
		if (word[0] >= 'A' && word[0] <= 'Z') {
			if (word[1] >= 'A' && word[1] <= 'Z') {
				int i;
				for (i = 1; i < word.length(); i++) {
					if (word[i]<'A' || word[i]>'Z') break;
				}
				if (i == word.length()) return true;
				else return false;
			}
			else 
			{
				int i;
				for (i = 1; i < word.length(); i++) {
					if (word[i]>='A' && word[i]<= 'Z') break;
				}
				if (i == word.length()) return true;
				else return false;
			}
		}
		else 
		{
			for (int j = 1; j < word.length(); j++) {
				if (word[j]>='A' && word[j]<='Z') return false;
		}
			return true;
		}
	}
};