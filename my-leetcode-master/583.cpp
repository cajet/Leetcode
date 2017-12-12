	/*
最大公共子序列，可以通过动态规划来求。首先，设word1中各个字符为s1,s2,……,sm，word2中各个字符为为t1,t2,……tn。而最大公共子序列为z1,z2……zk。
若sm=tn，明显则有zk=sm=tn，所以s1,s2,……,sm-1与t1,t2,……tn-1的最大公共子序列就为z1,z2……zk-1。
若sm≠tn，如果zk=sm，则z1,z2……zk是s1,s2,……,sm与t1,t2,……tn-1的最大公共子序列；
		同理若zk=tn，则z1,z2……zk是s1,s2,……,sm-1与t1,t2,……tn的最大公共子序列。
根据以上的规律，可以得出如下结论：
设dp[i][j]等于word1前i位与word2前j位的最大公共子序列长度。
当i=0或j=0，dp[i][j]=0；
当i>0且j>0，若word1[i]=word2[j],dp[i][j]= dp[i-1][j-1]+1;
当i>0且j>0，若word1[i]≠word2[j]，dp[i][j]=max（dp[i][j-1]，dp[i-1][j]）
	 */
	class Solution {
	public:
		int minDistance(string word1, string word2) {
			int m = word1.size(), n = word2.size();
			vector<vector<int>> v(m+1, vector<int>(n+1, 0));
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					if (word1[i-1] == word2[j-1]) v[i][j] = v[i - 1][j - 1] + 1;
					else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
				}
			}
			return m + n - 2 * v[m][n];
		}
	};