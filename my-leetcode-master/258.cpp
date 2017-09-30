class Solution {
public:
	int addDigits(int num) {
		while (1) {
			int temp = 0;
			while (num) {
				temp += num % 10;
				num = num / 10;
			}
			if (temp < 10) return temp;
			else num = temp;
		}
	}
};