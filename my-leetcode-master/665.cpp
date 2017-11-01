class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for (int i=0; i < nums.size()-1; i++){
            if (nums[i] > nums[i+1]){
                
                int temp = nums[i];
                nums[i] = nums[i+1];
                if (is_sorted(nums.begin(), nums.end())) { return true; }
                
                nums[i] = temp;
                nums[i+1] = nums[i];
                if (is_sorted(nums.begin(), nums.end())) { return true; }
                
                return false;
            }
        }
        return true;
    }
};