class Solution {
public:
    string reverseWords(string s) {
		stack<string> sta;
		string temp = "";
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] != ' ') {
				temp += s[i];
			}
			else {
				sta.push(temp);
				temp = "";
			}
		}
        sta.push(temp);
		string result = "";
		while (!sta.empty()) {
			result = result+ sta.top()+ ' ';
			sta.pop();
		}
		return result.substr(0, result.length() - 1);
	}
};