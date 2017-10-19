class Solution {
public:
	string convertToBase7(int num) {
		if (num == 0) return "0";
		bool neg = false;
		if (num < 0) {
            num= 0-num;
            neg = true;
        }
		string res = "";
		while (num) {
			res = to_string(num % 7)+ res;
			num = num / 7;
		}
		return neg ? "-" + res : res;
	}
};