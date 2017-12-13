class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //把出现过的字符都放入set中，遇到set中没有的字符就加入set中并更新结果res
        //如果遇到重复的，则从左边开始删字符，直到删到重复的字符停止：
        set<char> t;
        int right= 0, left= 0, MAX= 0;
        while (right< s.size()) {
            if (t.find(s[right]) == t.end()) {
                t.insert(s[right]);
                right++;
                if (t.size()> MAX) MAX= t.size();
            } else {
                t.erase(s[left]);
                left++;
            }
        }
        return MAX;
    }
};