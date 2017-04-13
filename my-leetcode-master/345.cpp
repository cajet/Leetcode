class Solution {
public:
    inline bool isY(char c) {
      return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
             c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string reverseVowels(string s) {
      vector<char> temp;
      int size = s.size();
      for (int i = size-1; i>=0; i--) {
        if (isY(s[i]))
          temp.push_back(s[i]);
      }

      int j = 0;
      for (int i = 0; i < size; i++) {
        if (isY(s[i]))
          s[i] = temp[j++];
      }
      return s;
    }
};