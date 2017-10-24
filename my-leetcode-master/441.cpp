class Solution {
public:
	int arrangeCoins(int n) {
		if (n == 0) return 0;
		int i;
		for (i = 1; n> 0; i++) {
			n = n - i;
		}
		if (n< 0) return i-2;
		else return i - 1;
	}
};