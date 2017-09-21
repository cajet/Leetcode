class Solution {
public:
    int findComplement(int num) {
        int temp= num;
        int sum= 1;
        while (num!= 0) {
            sum*=2;
            num/=2;
        }
        return sum-1-temp;
    }
};