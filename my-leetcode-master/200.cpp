class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()== 0) return 0;
        int row= grid.size(), col= grid[0].size(), sum= 0;
        for (int i= 0; i< row; i++) {
            for (int j= 0; j< col; j++) {
                if (grid[i][j] == '1') {
                    sum++;
                    dfs(i, j, grid);
                }
            }
        }
        return sum;
    }
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i< 0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(i+1, j, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i, j-1, grid);
    }
};