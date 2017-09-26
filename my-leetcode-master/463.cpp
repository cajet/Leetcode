class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {  //4*总island个数-每个island相邻的island个数之和
		int island = 0;
		int neighbor = 0;
		for (int i = 0; i<grid.size(); i++) {
			for (int j = 0; j<grid[i].size(); j++) {
				if (grid[i][j] == 1) {
					island++;
					if (j>0 && grid[i][j - 1] == 1)
						neighbor++;
					if (j + 1<grid[i].size() && grid[i][j + 1] == 1)
						neighbor++;
					if (i>0 && grid[i - 1][j] == 1)
						neighbor++;
					if (i + 1<grid.size() && grid[i + 1][j] == 1)
						neighbor++;
				}

			}
		}
		return (4 * island) - (neighbor);
	}
};