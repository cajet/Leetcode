class Solution {
public:
	int row[26] = { 1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2 };
	bool check(string str) {
		int val = row[tolower(str[0]) - 'a'];
		for (int i = 0; i < str.length(); i++) {
			if (row[tolower(str[i]) - 'a'] != val) return false;
		}
		return true;
	}
	vector<string> findWords(vector<string>& words) {
		vector<string> result;
		for (int i = 0; i <words.size(); i++) {
			if (check(words[i])) result.push_back(words[i]);
		}
		return result;
	}
}; 