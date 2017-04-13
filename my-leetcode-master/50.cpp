//  计算pow(x,n)， O(logn)时间复杂度
//  要注意n小于0的情况, 要考虑溢出的情况 2.00000 -2147483648

#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
      unsigned long m;
      if (n<0) {
        x = 1/x;
        m = -n;
      } else {
        m = n;
      }

      if (m==0) return 1;

      double ans = 1;
      while (m) {
        if (m%2==1)
          ans *= x;
        x *= x;
        m /= 2;
      }

      return ans;
    }
};


int main() {
  int n;
  double x;
  Solution s;
  while (cin >> x >> n) {
    cout << s.myPow(x, n) << endl;
  }
}