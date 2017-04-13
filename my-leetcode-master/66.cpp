class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int i = digits.size()-1;
      digits[i]++;
      for (; i > 0; i--) {
        if (digits[i] >= 10) {
          digits[i] %= 10;
          digits[i-1]++;
        }
      }

      if (digits[0]>=10) {
        digits[0]%=10;
        digits.insert(digits.begin(), 1);
      }
      return digits;
    }
};
