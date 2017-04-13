//  2016年 04月 24日 星期日 09:28:30 CST
//  https://leetcode.com/problems/triangle/
//  动态规划
//  每个位置的来源最多只有两个


class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
      int size = triangle.size(), i, j;
      if (size==0)
        return 0;

      int *dpre = new int[size], *dcur = new int[size], *tmp;
      fill(dpre, dpre+size, INT_MAX);
      dpre[0] = triangle[0][0];
      for (i = 1; i < size; i++) {
        //cout << "================第"<< i<<"层=============" << endl;
        for (j = 0; j < i; j++) {
          if (j==0)
            dcur[j] = dpre[j]+triangle[i][j];
          else
            dcur[j] = min(dpre[j-1], dpre[j]) + triangle[i][j];
        }

        dcur[j] = dpre[j-1]+triangle[i][j];
        tmp = dcur;
        dcur = dpre;
        dpre = tmp;
      }

      int min = INT_MAX;
      for (int i = 0; i < size; i++) {
        if (dpre[i] < min)
          min = dpre[i];
      }
      delete[] dpre;
      delete[] dcur;
      return min;
    }
};