class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int max_ = INT_MIN;
        int sum= 0;
		for (int i = 0; i < nums.size(); i++) {
			if (i< k) sum+= nums[i];
            else {
                max_= max(max_, sum);
                sum+= nums[i]-nums[i-k];
            }
		}
        max_= max(max_, sum);
		return (max_ + 0.0) / k;
	}
};