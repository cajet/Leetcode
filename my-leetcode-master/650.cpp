class Solution {
public:
	bool issushu(int num) {
		int i;
		for (i = 2; i <= sqrt(num); i++) {
			if (num%i == 0) break;
		}
		if (i > sqrt(num)) return true;
		else return false;
	}
	int minSteps(int n) {
		if (n == 1) return 0;
		if (issushu(n)) return n;
		for (int i = 2; i <= sqrt(n); i++)
			if (n % i == 0) return i + minSteps(n / i);
		return n;
	}
};