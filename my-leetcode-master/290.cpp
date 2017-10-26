class Solution {
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> m;
		for (int i = 0; i < pattern.length(); i++) {   //初始化map
			m[pattern[i]] = "";
		}
		vector<string> v;
		string temp = "";
		for (int i = 0; i < str.length(); i++) {  //按空格截取str存到vector中
			if (str[i] == ' ') {
				v.push_back(temp);
				temp = "";
			}
			else {
				temp += str[i];
			}
		}
		v.push_back(temp);  //注意最后一个没有空格

		if (pattern.length() != v.size()) return false;
		set<string> s;   //存储map里面的string,检查是否出现不同char映射到同一个string的情况 ex: abba  ->  dog dog dog dog
		for (int i = 0, j = 0; i < pattern.length() && j < v.size(); i++, j++) {
			if (m[pattern[i]] == "") {
				if (s.find(v[j]) == s.end()) {
					m[pattern[i]] = v[j];
					s.insert(v[j]);
				}
				else return false;
			}
			else if (m[pattern[i]] != v[j]) return false;
		}
		return true;
	}
};