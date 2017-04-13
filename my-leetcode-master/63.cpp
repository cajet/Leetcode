class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
      int m = obstacleGrid.size();
      if (m==0)
        return 0;
      int n = obstacleGrid[0].size();
      if (n==0)
        return 0;

      int dp[m][n], i, j;
      for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++)
          dp[i][j] = 0;
      }
      //第一列
      i = 0;
      while(i<m) {
        if (obstacleGrid[i][0]!=1)
          dp[i++][0] = 1;
        else
          break;
      }
      while(i<m)
        dp[i++][0]=0;

      //第一行
      i = 0;
      while(i<n) {
        if (obstacleGrid[0][i]!=1)
          dp[0][i++] = 1;
        else
          break;
      }
      while(i<n)
        dp[0][i++]=0;
    //cout << "hh" << endl;
    for (i = 1; i < m; i++) {
      for (j = 1; j < n; j++) {
        if (obstacleGrid[i][j]==1)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i-1][j]+dp[i][j-1];
      }
    }

    return dp[m-1][n-1];
  }
};
