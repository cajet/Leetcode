class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(n+1);
        for(int i=1; i<=n; i++) nums[i] = i;  
        for(int i=1; i<=n; i++) {  
            for(int j=1; j*j<=i; j++) {  
                nums[i] = min(nums[i], nums[i-j*j]+1);  
            }  
        }  
        return nums[n];  
    }
};