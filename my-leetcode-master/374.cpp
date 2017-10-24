// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low= 1, high= n, mid;
        while (low<= high) {
            mid= low+(high-low)/2;
            if (guess(mid) == 1) low= mid+1;
            else if (guess(mid)==-1) high= mid-1;
            else return mid;
        }
        return -1;
    }
};