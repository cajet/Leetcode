//  2016年 03月 26日 星期六 19:31:56 CST
//  https://leetcode.com/problems/two-sum/

//  CopyRight@1900zengyh
//  数组问题


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int size = nums.size(), i, j=size-1, sum;
      vector<int> ans;
      vector<pair<int, int> > tmp;
      for (i=0; i < size; i++)
        tmp.push_back(pair<int, int>(nums[i], i));
      sort(tmp.begin(), tmp.end());

      for (i = 0; i < size-1; i++) {
        for (; j>i; j--) {
          sum = tmp[i].first+tmp[j].first;
          if (sum == target) {
            ans.push_back(tmp[i].second);
            ans.push_back(tmp[j].second);
            sort(ans.begin(), ans.end());
            return ans;
          } else if (sum < target) {
            break;
          }
        }
      }
    }
};