class Solution {
public:
	bool judgeSquareSum(int c) {
        for (int i= 0; i<= sqrt(c); i++) {
            int remain= c- i*i;
            int temp = sqrt(remain);
            if (temp*temp == remain) return true;
        }
        return false;
	}
};