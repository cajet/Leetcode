class Solution {
public:
    inline char tolow(char c) {
      if (c>='A'&&c<='Z')
        return c-'A'+'a';
      else
        return c;
    }

    inline bool check(char c) {
      return (c<='9' && c>='0') || (c<='z' && c>='a') ||(c>='A' && c<='Z');
    }


    bool isPalindrome(string s) {
      int size = s.length();

      if (size == 0)
        return true;

      int i = 0;
      int j = size-1;
      while (i != j) {
        while (i < size && !check(s[i]))
          i++;

        while (j >= 0 && !check(s[j]))
          j--;

        if (i > j)
          break;

        if (tolow(s[i]) != tolow(s[j]))
          return false;

        if (i == j-1 || i == j)
          break;

        i++;
        j--;
      }
      return true;
    }
};

int main() {
  string s;
  Solution zyh;
  while (cin >> s)
    cout << zyh.isPalindrome(s) << endl;
}