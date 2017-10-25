//解法一超时
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        map<char, int> m;
        for (int i = 0; i < p.length(); i++) {
            m[p[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s.length() - i < p.length()) continue;
            map<char, int> m_copy = m;
            int j = i;
            bool flag = true;
            int end = j + p.length();
            while (j < end) {
                m_copy[s[j]]--;
                if (m_copy[s[j]] < 0) {
                    flag = false;
                    break;
                }
                j++;
            }
            if (flag) v.push_back(i);
        }
        return v;
    }
};

//用vector取代map
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
        vector<int> res, cnt(256, 0);
        int ns = s.size(), np = p.size(), i = 0;
        for (char c : p) ++cnt[c];
        while (i < ns) {
            bool success = true;
            vector<int> tmp = cnt;
            for (int j = i; j < i + np; ++j) {
                if (--tmp[s[j]] < 0) {
                    success = false;
                    break;
                }
            }
            if (success) {
                res.push_back(i); 
            }
            ++i;
        }
        return res;
	}
};