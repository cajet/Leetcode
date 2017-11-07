class Solution {
    int findTargetSumWays(int[] nums, int S) {
        int result = 0;
        if (nums == null || nums.length == 0) return result;
        helper(nums, S, 0, 0);
        return result;
    }
    
    void helper(int[] nums, int target, int pos, long eval){
        if (pos == nums.length) {
            if (target == eval) result++;
            return;
        }
        helper(nums, target, pos + 1, eval + nums[pos]);
        helper(nums, target, pos + 1, eval - nums[pos]);
    }
};