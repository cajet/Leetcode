class Solution {
public:
    int climbStairs(int n) {
      int ans[100];
      ans[0] = ans[1] = 1;
      for (int i = 2; i < 100; i++)
        ans[i] = ans[i-1]+ans[i-2];

      return ans[n];
    }
};
