class Solution {
public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		if (grid.size() == 0) return 0;
		int row = grid.size();
		int col = grid[0].size();
		int MAX = 0;
		for (int i = 0; i< row; i++) {
			for (int j = 0; j< col; j++) {
				if (grid[i][j] == 1) {
				    MAX = max(MAX, dfs(i, j, grid));
                }
			}
		}
		return MAX;
	}
	int dfs(int row, int col, vector<vector<int>>& grid) {
        grid[row][col] = 0;
        int area= 1;
        vector<int> dir({-1,0,1,0,-1});
        for (int i= 0; i< 4; i++) {
            int new_row= row+dir[i], new_col= col+dir[i+1];
            if (new_row >= 0 && new_row < grid.size() && new_col >= 0 && new_col < grid[0].size() && grid[new_row][new_col] == 1)
                area+= dfs(new_row, new_col, grid);
        }
        return area;
	}
};