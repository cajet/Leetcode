class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end());
		int count, max = 0, k, j;
		string temp, res;
		for (int i = 0; i < d.size(); i++) {
			temp = d[i];
			count = 0;
			for (j = 0, k = 0; j < s.size() && k < temp.size();) {
				if (s[j] == temp[k]) {
					j++;
					k++;
					count++;
				}
				else {
					j++;
				}
			}
			if (k == temp.size() && count > max) {
				res = temp;
				max = count;
			}
		}
		return res;
    }
};