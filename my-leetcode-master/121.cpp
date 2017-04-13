class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      if (size==0)
        return 0;
      int end, minstart, res;
      res = 0;
      minstart = prices[0];

      for (int i = 1; i < size; i++) {
        end = prices[i];
        res = (res>end-minstart)?res:end-minstart;
        minstart = (end<minstart)?end:minstart;
      }

      return res;
    }
};
