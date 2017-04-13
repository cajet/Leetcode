class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
      vector<vector<int> > ans;
      if (n==k||k==0) {
        vector<int> tmp;
        for (int i = 1; i <= k; i++)
          tmp.push_back(i);
        ans.push_back(tmp);
      } else {
        ans = combine(n-1, k-1);
        for (int i = 0; i < ans.size(); i++)
          ans[i].push_back(n);
        vector<vector<int> > tmp = combine(n-1, k);
        for (int i = 0; i < tmp.size(); i++)
          ans.push_back(tmp[i]);
      }
      return ans;
    }
};
