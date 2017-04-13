class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int size = nums.size();
      int max, sum=0;
      max = nums[0];
      //max记录最大连续和的结果，sum记录当前的求和结果

      for (int i = 0; i < size; i++) {
        sum += nums[i];
        //一旦左边的sum小于0，就没有将这个串往右继续传递的意义了
        max = (max>sum?max:sum);
        sum = (sum>0?sum:0);
      }

      return max;
    }
};