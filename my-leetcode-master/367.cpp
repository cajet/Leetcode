class Solution {
public:
    bool isPerfectSquare(int num) {
         if(num == 0 || num == 1) return true;
         for (int i = 1; i<= num/i; ++i) {
            if (i * i == num) return true;
        }
        return false;
    }
};