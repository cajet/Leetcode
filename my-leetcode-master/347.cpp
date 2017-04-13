bool com(const pair<int, int>& p1, const pair<int, int>& p2) {
  return p1.second > p2.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int, int> table;
      vector<pair<int,int> > vec;
      vector<int> ans;
      for (int i = 0; i < nums.size(); i++) {
        if (table.find(nums[i])==table.end())
          table.insert(pair<int, int>(nums[i], 1));
        else
          table[nums[i]]++;
      }

      for (map<int, int>::iterator it=table.begin(); it!=table.end(); it++)
        vec.push_back(*it);
      sort(vec.begin(), vec.end(), com);

      for (int i = 0; i < k; i++) 
        ans.push_back(vec[i].first);

      return ans;
    }
};
