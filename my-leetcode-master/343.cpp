#include<algorithm>
#include<iostream>
using namespace std;

int mmax(int a, int b) {
  if (a > b)
    return a;
  return b;
}

class Solution {
public:
    int integerBreak(int n) {
      int* arr = new int[n+1];
      int tmp = 0, max = 1;
      fill(arr, arr+n+1, 1);
      arr[3]=2;

      for (int i = 4; i <= n; i++) {
        for (int j = 2; j <= i/2; j++) {
          tmp = mmax(j*(i-j), arr[j]*arr[i-j]);
          tmp = mmax(j*arr[i-j], tmp);
          arr[i] = mmax(arr[i], tmp);
        }
      }

      max = arr[n];
      delete[] arr;
      return max;
    }
};


int main() {
  Solution s;
  int n;
  while (cin >> n) {
    cout << s.integerBreak(n) << endl;
  }
}