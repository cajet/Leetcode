 /*
        标准的动态规划题目，难点在于想出将两个字符串删除到相同的过程
        这里从两个字符串的开头字符考虑，一个一个得考虑到最后一个，我们用二维数组dp[i][j]代表字符串1前i个字符和字符串2前j个字符实现相同所需要
       删除的ASCII value,有三种方法可以到达dp[i][j]:
       1.dp[i-1][j] + str1[i]:由于从dp[i-1][j]到dp[i][j]是多考虑了str1的一个字符，但是str2字符数没变，所以要想相同，必须删除str1[i],考虑value的话就是加上str1[i]
       2.dp[i][j-1] + str2[j]:对应于1，这个是多考虑str2的一个字符，所以要删除str2[j]
       3.dp[i-1][j-1] + a，这里是考虑两个str都加了一个，所以str1[i] =str2[j]时，a=0；str1[i] ！=str2[j]时，两个都要删除，a=str1[i] +str2[j]
       这三种情况每次比较出最小的来，最后返回dp[str1.length][str2.length](这里字符串下标从1开始，因为我们考虑dp数组的第0行代表str1还啥也没有，第0列代表str2啥也没有)
         */

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<vector <int> > dp(m+1 ,vector<int>(n+1));  
        for (int i = 1; i < m+1; i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for (int j = 1; j < n+1; j++) dp[0][j] = dp[0][j-1] + s2[j-1];
        for (int i = 1; i < m+1; i++)
        {
            for (int j = 1; j < n+1; j++)
            {
               int a = (s1[i-1] == s2[j-1])? 0 : s1[i-1]+s2[j-1];
                //比较三种情况
                dp[i][j] = min(dp[i-1][j-1]+a, min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]));
            }
        }
        return dp[m][n];
    }
};