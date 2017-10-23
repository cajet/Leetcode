class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		bool carry = true;
        for(int i=digits.size()-1; i >= 0 && carry; i--) {
            ++digits[i];
            if (digits[i] == 10) {
                carry = true;
                digits[i]= 0;
            } else {
                carry= false;
            }
        }
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
	}
};