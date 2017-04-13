class Solution {
public:
    void fillcol(vector<vector<int> >& matrix, int col) {
      int m = matrix.size();
      for (int i = 0; i < m; i++) {
        matrix[i][col] = 0;
      }
    }

    void fillrow(vector<vector<int> >& matrix, int row) {
      int n = matrix[0].size();
      for (int j = 0; j < n; j++)
        matrix[row][j] = 0;
    }

    void setZeroes(vector<vector<int> >& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      int i, j;

      //judge if the first col should be set 0 
      int col0 = 1;
      for (i = 0; i < m; i++) {
        //cout << matrix[i][0] << endl;
        if (matrix[i][0] == 0) {
          col0 = 0;
          break;
        }
      }

      //judge if the rows should be set 0
      for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
          if (matrix[i][j]==0) {
            matrix[i][0] = 0;
            break;
          }
        } 
      }

      //judge if the cols should be set 0
      for (j = 1; j < n; j++) {
        for (i = 0; i < m; i++) {
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;
            break;
          }
        }
      }

      //from bottom right, set the row&col
      for (j = n-1; j > 0; j--) {
        if (matrix[0][j] == 0) {
          fillcol(matrix, j);
        }
      }

      for (i = m-1; i >= 0; i--) {
        if (matrix[i][0]==0)
          fillrow(matrix, i);
      }

      if (col0==0)
        fillcol(matrix, 0);
    }
};