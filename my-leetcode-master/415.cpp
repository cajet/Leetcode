class Solution {
public:
	string addStrings(string num1, string num2) {
		//先给短的字符串补0，使两个字符串长度相同
		int length1 = num1.length(), length2 = num2.length();
		if (length1 < length2) {
			while (length1 != length2) {
				num1 = to_string(0) + num1;
				length1++;
			}
		}
		else if (length1 > length2) {
			while (length1 != length2) {
				num2 = to_string(0) +num2;
				length2++;
			}
		}
		//cout << num1 << " " << num2 << endl;
		string res = "";
		bool jinwei = false;
		int i, j;
		for ( i = num1.size() - 1, j = num2.size() - 1; i >= 0 && j >= 0; i--, j--) {
			if (jinwei == false) {
				if ((num1[i] - '0') + (num2[j] - '0') > 9) {
					res = to_string((num1[i] - '0') + (num2[j] - '0') - 10) + res;
					jinwei = true;
				}
				else {
					res = to_string((num1[i] - '0') + (num2[j] - '0')) + res;
					jinwei = false;
				}
			}
			else {
				if ((num1[i] - '0') + (num2[j] - '0') + 1 > 9) {
					res = to_string((num1[i] - '0') + (num2[j] - '0') -9) + res;
					jinwei = true;
				}
				else {
					res = to_string((num1[i] - '0') + (num2[j] - '0') + 1) + res;
					jinwei = false;
				}
			}
		}
		if (jinwei) res = "1" + res;
		return res;
	}
};