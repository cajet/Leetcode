//  判断是否在同一列用abs(index1-idnex2)和abs(x[index1]-x[index2])是否相等
//  1.简单回溯法
//  2.改进版1：将各行各列的状态bool数组存起来，每次只需要访问数组就可以知道当前哪些格子不能放
//  3.改进版2：


class Solution {
public:
    int totalNQueens(int n) {
      int table[n];
      int method=0;
      place(table, method, n, 0);
      return method;
    }

    void place(int *table, int& method, const int& n,  int index) {
      int i, j;
      for (i = 0; i < n; i++) {
        for (j = 0; j < index; j++) {
          if (table[j]==i||abs(j-index)==abs(table[j]-i))
            break;
        }

        if (j==index) {
          table[index] = i;
          if (index==n-1) 
            method++;
          else
            place(table, method, n, index+1);
        }
      }
    }
};
