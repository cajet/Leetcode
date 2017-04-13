class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      if (size==0)
        return 0;

      int res = -prices[0];
      int end = prices[0];

      for (int i = 1; i < size; i++) {
        if (prices[i] < end)
          res += end-prices[i];
        end = prices[i];
      }

      res += prices[size-1];
      return res;
    }
};
