#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            ans ^= nums[i];
        return ans; 
    }
};

int main() {
    int n;
    vector<int> nums;
    Solution result;
    while ((cin >> n) != 0)
        nums.push_back(n);
    cout << result.singleNumber(nums) << endl;
}