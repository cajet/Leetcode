class Solution {
public:
    int numDistinct(string s, string t) {
      int m = t.size(), n = s.size();
      vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
      for (int i = 0; i <= n; i++)
        dp[0][i] = 1;             //空串在任何字符串中出现次数都为1
      for (int i = 1; i <= m; i++)
        dp[i][0] = 0;             //任何非空串在空串中出现次数都为0

      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          if (s[j-1] == t[i-1])     //若s最后一个和t不相等，就不用考虑s的这一个了，直接为dp[i][j-1]
            dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
          else                      //若最后一个字符相等，则加上不考虑最后一个字符的个数
            dp[i][j] = dp[i][j-1];
        }
      }

      return dp[m][n];
    }
};  
