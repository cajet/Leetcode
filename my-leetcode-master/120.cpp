class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) { //自底向上
        int length = triangle.size();
        if(length == 0) return 0;
        if(length == 1) return triangle[0][0];  
        vector<vector<int>> MP(length, vector<int>(triangle.size(), 0));
        MP[length-1]=triangle[length-1];//三角形底部一行任何一个位置达到底部最短路径为其本身
        for(int i = length-2; i >= 0; i--)
        {
            for(int j = 0; j< triangle[i].size(); j++)
            {
                MP[i][j]=min(MP[i+1][j], MP[i+1][j+1])+triangle[i][j];
            }
        }
        return MP[0][0];
    }
};