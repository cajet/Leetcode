class Solution {
public:
    vector<int> countBits(int num) {
      vector<int> ans;
      ans.push_back(0);
      int times=1, j = 0;
      for (int i = 1; i <= num; i++) {
        ans.push_back(ans[i-times+j]+1);
        j++;
        if (j == times) {
          j = 0;
          times *= 2;
        }
      }

      return ans;
    }
};
