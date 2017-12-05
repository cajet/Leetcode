class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int> > len(m, vector<int>(n, 0));
        // first row
        for(int i = 0; i < n; i ++)
        {
            len[0][i] = (int)(matrix[0][i]-'0');
            if(len[0][i] == 1) maxLen = 1;
        }
        // first col
        for(int i = 0; i < m; i ++)
        {
            len[i][0] = (int)(matrix[i][0]-'0');
            if(len[i][0] == 1) maxLen = 1;
        }
        for(int i = 1; i < m; i ++)
        {
            for(int j = 1; j < n; j ++)
            {
                if(matrix[i][j] == '0') len[i][j] = 0;
                else
                {
                    len[i][j] = min(min(len[i-1][j], len[i][j-1]), len[i-1][j-1]) + 1;
                    maxLen = max(len[i][j], maxLen);
                }
            }
        }
        return maxLen * maxLen;
    }
};