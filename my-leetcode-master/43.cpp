//  法1：基于高精度加法实现高精度乘法
//  法2：模拟笔算过程（未实现）

class Solution {
public:
    void addition(string& num1, string num2) {
      while (num1.size()<num2.size())
        num1.insert(0, 1, '0');
      while (num2.size()<num1.size())
        num2.insert(0, 1, '0');
      num1.insert(0, 1, '0');
      num2.insert(0, 1, '0');
      //cout << "! " << num1 << "! " << num2 << endl;

      int s1 = num1.size();
      for (int i = s1-1; i>0; i--) {
        num1[i]+=num2[i]-'0';
        if (num1[i]>'9') {
          num1[i]='0'+(num1[i]-'0')%10;
          num1[i-1]++;
        }
      }

      while (num1.size()>1&&num1[0]=='0')
        num1.erase(0, 1);
    }

    string multiply(string num1, string num2) {
      if (num1=="0"||num2=="0")
        return "0";
      if (num2.size()>num1.size()) {
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
      }

      string origin=num1;
      int size= num2.size();
      num1="0";
      for (int i = 0; i<size; i++) {
        int n = num2[i]-'0';
        for (int j = 0; j < n; j++) {
          addition(num1, origin);
        //cout << "* " << num1 << endl;
        }
        if (i!=size-1)
          num1+="0";

      }
      return num1;
    }
};