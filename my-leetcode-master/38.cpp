class Solution {
public:
    string countAndSay(int n) {
      string s = "1", s2;
      int size, k, i, j;

      for (k = 1; k < n; k++) {
        size = s.size();
        //cout << "s:  " << s << ",  size: " << size << endl;
        for (j = 0; j < size; j++) {
          i = 1;
          while (s[j]==s[j+1]) {
            i++;
            j++;
          }
          s2 += '0'+i;
          s2 += s[j];
        }
        s = s2;
        s2 = "";
      }

      return s;
    }
};

