class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0, maxCnt = 0, start = 0;
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            counts[s[i] - 'A']++;
            maxCnt = max(maxCnt, counts[s[i] - 'A']);  //maxCnt记录出现次数最多的字符的个数
            while (i - start + 1 - maxCnt > k) {  //不满足(子字符串的长度减去出现次数最多的字符个数)<=k的最大子字符串长度
                --counts[s[start] - 'A'];
                ++start;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};