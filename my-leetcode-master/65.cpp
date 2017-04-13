#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
      int i = 0, size=s.size();
      int n1=0, n2=0x80000001, n3=0xffffffff;
      bool e=false, dot=false;

      while(s[i]==' '&&i<size)
        i++;

      while(i<size) {

      }

    }
};


int main() {
  string str="-1. ";
  Solution s;
  //while(cin >> str)
    cout << s.isNumber(str) << endl;
}