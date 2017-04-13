//  数组问题：顺时针旋转90度, 找规律
//  先上下行之间反序，之后沿对角线交换

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
      reverse(matrix.begin(), matrix.end());
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < i; j++) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }
    }
};
