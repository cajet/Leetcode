class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
      map<string, multiset<string> > mp;
      vector<vector<string> > ans;
      
      for (int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].insert(strs[i]);
      }

      for (map<string, multiset<string> >::iterator it = mp.begin(); it!=mp.end(); it++) {
        vector<string> tmp;
        for (multiset<string>::iterator itt = it->second.begin(); itt!=it->second.end(); itt++) {
          tmp.push_back(string(itt->begin(), itt->end()));
        }
        ans.push_back(tmp);
      }


      return ans;
    }
};


