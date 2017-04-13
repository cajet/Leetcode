class Solution {
public:
    vector<int> grayCode(int n) {
      int max = 1<<n;
      vector<int> ans;
      for (int i = 0; i < max; i++) {
        ans.push_back((i>>1)^i);
      }

      return ans;
    }
};