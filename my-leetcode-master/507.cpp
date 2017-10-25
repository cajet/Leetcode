class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num == 1) return false;
		int count = 1;
		for (int i = 2; i <= sqrt(num); i++) {
			if (num%i == 0) {
				count += i;
				if (num / i != i) count += num / i;
			}
		}
		if (count == num) return true;
		else return false;
	}
};