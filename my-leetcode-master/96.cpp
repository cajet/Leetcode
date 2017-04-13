class Solution {
public:
    int numTrees(int n) {
      int* G = new int[n+1];
      fill(G, G+n+1, 0);
      G[0]=G[1]=1;

      for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
          G[i] += G[j-1]*G[i-j];
        }
      }

      int ans = G[n];
      delete[] G;
      return ans;
    }
};

