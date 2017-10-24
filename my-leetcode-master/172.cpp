class Solution {
public:
    int trailingZeroes(int n) {
        int c = 0;   
        while(n/5 != 0) {    //计算n!中5的个数
            n /= 5;   
            c += n;   
        }   
        return c;   
    }
};