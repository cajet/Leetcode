class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            s = char ((n - 1) % 26 + 'A') + s;
            n = (n - 1) / 26;
        }
        return s;
    }
};