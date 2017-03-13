class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int ans= 0;
        int temp= x;
        while (temp) {
            ans= ans*10 + temp%10;
            temp/= 10;
        }
        if (ans == x) return true;
        else return false;
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
