class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
      vector<vector<int> > ans(n, vector<int>(n, 0));
      if (n==0)
        return ans;
      int top=0, bottom=n-1, left=0, right=n-1, i=1, j=0;
      while (i <= n*n) {
        //turn right
        for (j = left; j <= right; j++, i++)
          ans[top][j] = i;
        top++;
        //turn left
        for (j = top; j <= bottom; j++, i++)
          ans[j][right] = i;
        right--;
        //turn right
        for (j = right; j >= left; j--, i++)
          ans[bottom][j] = i;
        bottom--;
        //turn up
        for (j = bottom; j >= top; j--, i++)
          ans[j][left] = i;
        left++;
      }
      ans[n/2][(n-1)/2] = n*n;
      return ans;
    }
};

