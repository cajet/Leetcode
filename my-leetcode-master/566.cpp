class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int row = nums.size();
		int column = nums[0].size();
		vector<vector<int>> new_nums(r,vector<int>(c)); //注意指定大小
		if (r*c != row*column ) 
		{
			return nums;
		}
		else {
			row = 0;
			column = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					new_nums[i][j] = nums[row][column];
					column++;
					if (column == nums[0].size()) {
						column = 0;
						row++;
					}
				}
			}
		}
        return new_nums;
	}
};