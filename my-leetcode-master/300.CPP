class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if(nums.size() == 0) return 0;
        vector<int> a(nums.size(), 1);
        int MAX = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[i]> nums[j]){
                    a[i] = max(a[j]+1, a[i]);
                }
            }
            MAX = max(MAX, a[i]);
        }
        return MAX;
	}
};