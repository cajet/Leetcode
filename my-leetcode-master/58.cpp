class Solution {
public:
    int lengthOfLastWord(string s) {
      int size = s.size(), i = size-1;
      while (i>=0) {
        if (s[i]!=' ')
          break;
        i--;
      }

      int ans = 0;
      while (i>=0) {
        if (s[i]==' ')
          break;
        ans++;
        i--;
      }
      
      return ans;
    }
};
