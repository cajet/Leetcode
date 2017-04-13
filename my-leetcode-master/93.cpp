class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
      int size = s.size();
      return dfs(s, 0, 0);
        
    }

    vector<string> dfs(string s, int index, int times) {
      //cout << "index: " << index << ", times: " << times << endl;
      vector<string> ans;
      int size = s.size(), num=0, i, j;
      if (index>=size)
        return ans;

      if (times == 3) {
        num = 0;
        if (size-index>=2&&s[index]=='0')
          return ans;

        for (i = index; i < size; i++)
          num = (num*10+s[i]-'0');
        if (num<=255&&size-index<=3)
          ans.push_back(s.substr(index, size-index));
      } else {
        for (i = 1; i <= 3; i++) {
          if (i>1&&s[index]=='0')
            continue;
          num = 0;
          for (j = index; j < index+i; j++)
            num = num*10+(s[j]-'0');
          if (num<=255) {
            vector<string> son = dfs(s, index+i, times+1);
            string tmp = s.substr(index, i);
            if (!son.empty()) {
              for (j = 0; j < son.size(); j++)
                ans.push_back(tmp+'.'+son[j]);
            }
          }
        }
      }

      return ans;
    }
};
