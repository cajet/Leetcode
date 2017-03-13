class Solution {
public:
    int reverse(int x) {
    	bool isnegative= false;
        if (x< 0) {
        	isnegative= true;
        	x= -x;
		}
		int ans= 0;
		int temp;
		while (x) {
			temp= ans*10 + x%10;
			if (temp/10 != ans) return 0;  //еп╤от╫╫Г 
			ans= temp;
			x/= 10;
		}
      	if (isnegative) return -ans;
      	else return ans;
    }
};



class Solution {
public:
    int reverse(int x) {
        long long j = 0;
    	do {
    		j = j * 10 + x % 10;
    	} while (x /= 10);
        return (j > INT_MAX || j < INT_MIN) ? 0: (int)j;
    }
};
