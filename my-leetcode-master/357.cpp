//通项公式为f(k) = 9 * 9 * 8 * ... (9 - k + 2)，k>= 2 
//那么我们就可以根据n的大小，把[1, n]区间位数通过通项公式算出来累加起来即可
class Solution {
public:
    int Count(int k) {
        if (k == 1) return 10;
        int pro= 9;
        for (int i= 9; i>= 11-k; i--) {
            pro*= i;
        }
        return pro;
    }
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res= 0;
        for (int i= 1; i<= n; i++) {
            res+= Count(i);
        }
        return res;
    }
};