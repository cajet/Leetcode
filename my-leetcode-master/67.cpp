class Solution {
public:
    string addBinary(string a, string b) {
      while (a.size()<b.size())
        a.insert(0, 1, '0');
      while (a.size()>b.size())
        b.insert(0, 1, '0');
      a.insert(0, 1, '0');
      b.insert(0, 1, '0');

      int size = a.size();
      for (int i = size-1; i > 0; i--) {
        a[i]+=b[i]-'0';
        if (a[i]>'1') {
          a[i] = '0'+(a[i]-'0')%2;
          a[i-1]++;
        }
      }

      while (a.size()!=1&&a[0]=='0')
        a.erase(0, 1);
      return a;
    }
};
