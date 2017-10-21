class Solution {
public:
	int findLHS(vector<int>& nums) {
		sort(nums.begin(), nums.end());
        int left = 0;
        int right = 0;
        int max_len = 0;
        while(left <= right && right < nums.size()){
            if(nums[right] - nums[left] == 1){
                max_len = max(max_len, right - left + 1);
                right++;
            } else if(nums[right] - nums[left] < 1){
                right++;
            } else {
                left++;
            }
        }
        return max_len;
	}
};
