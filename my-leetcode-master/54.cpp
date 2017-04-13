class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
      vector<int> ans;
      int m=matrix.size();
      if (m==0)
        return ans;
      int n=matrix[0].size(), i, j;
      int top=0, bottom=m-1, left=0, right=n-1;

      i = 0;
      while (i < m*n) {
        for (j = left; top <= bottom && j <= right; j++, i++)
          ans.push_back(matrix[top][j]);
        top++;
        for (j = top; left <= right && j <= bottom; j++, i++)
          ans.push_back(matrix[j][right]);
        right--;
        for (j = right; top <= bottom && j >= left; j--, i++)
          ans.push_back(matrix[bottom][j]);
        bottom--;
        for (j = bottom; left <= right && j >= top; j--, i++)
          ans.push_back(matrix[j][left]);
        left++;
      }
      return ans;
    }
};
