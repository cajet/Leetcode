class Solution {
public:
    int integerBreak(int n) {
        if(n < 4) return n-1;
        int res = 1;
        while(n > 2){//看n包含多少个3,把他们相乘,直到n<=2
            res *= 3;
            n -= 3;
        }
        if(n == 0) return res;//n可以整除3，res就是各个3相乘
        if(n == 1) return (res / 3 ) * 4;//除3余1，把其中的一个3加1变为4再相乘
        if(n == 2) return res * 2;//除3余2,则可直接把2与res相乘
    }
};