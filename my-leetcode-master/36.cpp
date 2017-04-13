//  遍历数组+哈希
//  数独的规则：每行/每列/每个九宫格  1~9只会出现一次


#include<bitset>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      bitset<9> Row[9];
      bitset<9> Col[9];
      bitset<9> box[9];
      int num;
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (board[i][j]!='.') {
            num = board[i][j]-'0'-1;
            if (Row[i].test(num) || Col[j].test(num) || box[(i/3)*3+j/3].test(num))
              return false;
            Row[i].set(num);
            Col[j].set(num);
            box[(i/3)*3+j/3].set(num);
          }
        }
      }

      return true;
    }
};