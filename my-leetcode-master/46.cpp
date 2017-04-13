//  全排列问题
//  1. next_permutation函数
//  2.递归+dfs
//  3.回溯

class Solution {
public:
    vector<vector<int> > permute1(vector<int>& nums) {
      vector<vector<int> > ans;
      int s1 = nums.size(), s2=1;
      for (int i = 2; i <= s1; i++)
        s2*=i;
      ans.push_back(nums);
      for (int i = 0; i < s2-1; i++) {
        next_permutation(nums.begin(), nums.end());
        ans.push_back(nums);
      }
      return ans;
    }

    vector<vector<int> > permute(vector<int>& nums) {
      vector<vector<int> > ans;
      permutation(nums, ans, 0);
      return ans;
    }

    //每个数都作为1次begin的位置
    void permutation(vector<int>& nums, vector<vector<int> >& ans, int begin) {
      if (begin>=nums.size()) {
        ans.push_back(nums);
        return;
      }

      for (int i = begin; i < nums.size(); i++) {
        swap(nums[begin], nums[i]);
        permutation(nums, ans, begin+1);
        swap(nums[begin], nums[i]);
      }
    }
};

