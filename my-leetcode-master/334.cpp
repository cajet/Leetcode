//  2016年 04月 24日 星期日 09:28:30 CST
//  https://leetcode.com/problems/increasing-triplet-subsequence/
//  c1表示三格移动窗口的第一个，c2表示三格移动窗口的第二个
//  基本原则是c1和c2有更小的值可替换的时候替换，当
//  x大于c1和c2时，说明存在有递增3个数


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int c1=INT_MAX, c2=INT_MAX;
      for (int i = 0; i < nums.size(); i++) {
        if (nums[i]<=c1)     
          c1 = nums[i];
        else if (nums[i]<=c2)
          c2 = nums[i];
        else
          return true;
      }
      return false;
    }
};