class Solution {
public:
    int hammingDistance(int x, int y) {
        string a= TenToTwo(x);
        string b= TenToTwo(y);
        int count= 0;
        for (int i= 0; i< 32; i++) {
            if (a.at(i) != b.at(i)) count++;
        }
        return count;
    }
    string TenToTwo(int x) {
    string result = "";
	int temp;
	while (x != 0) {
		char a= x % 2 + '0';
		result = result + a ;
		x = x / 2;
	}
	while (result.length() < 32) {
		result += "0";
	}
	return result;
    }
};