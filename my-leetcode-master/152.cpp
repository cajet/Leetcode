class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 1) return 0;  
        if(nums.size() < 2) return nums[0];  
        int global = nums[0];  
        int MAX = nums[0], MIN = nums[0];  
        for(int i=1; i< nums.size(); i++) {  
            int a = MAX*nums[i];  
            int b = MIN*nums[i];  
            MAX = max(nums[i], max(a, b));  
            MIN = min(nums[i], min(a, b));  
            global = max(MAX, global);  
        }  
          
        return global; 
    }
};