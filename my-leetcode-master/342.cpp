class Solution {
public:
    bool isPowerOfFour(int num) {
      int i = 4;
      if (num==1||num==0)
        return num;
      else if (num < 0)
        return false;
      while(i<=0x40000000&&i>0) {
        if ((int)(i&num)==num)
          return true;
        i<<=2;
      }
      return false; 
    }
};

