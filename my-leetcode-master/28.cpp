class Solution {
public:
    int strStr(string haystack, string needle) {
      int s1=haystack.size(), s2=needle.size(), i=0, j=0;
      if (haystack==needle)
        return 0;
      else if (haystack!=needle&&s1<=s2)
        return -1;

      for (i = 0; i < s1; i++) {
        j=0;
        while (haystack[i+j]==needle[j]&&i+j<s1&&j<s2)
          j++;
        if (j==s2)
          return i;
      }
      return -1;
    }
};


class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle) == string::npos ? -1 : haystack.find(needle);  
    }
};