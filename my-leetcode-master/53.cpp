class Solution {
public:
int maxSubArray(vector<int>& nums) {
	if (nums.size() <= 0)  return 0;  
    if (nums.size() == 1) return nums[0];
    int global = nums[0];  
    int MAX = nums[0];  
    for (int i= 1; i <nums.size(); i++)  
    {  
        MAX = max(nums[i], MAX + nums[i]);  
        global = max(MAX, global);  
    }  
    return global;  
}
};