#include<iostream>
using namespace std;
int getNum(char a) {
	int num;
    switch (a) {
    	case 'I':
    		num= 1;
    		break;
    	case 'V':
    		num= 5;
    		break;
    	case 'X':
    		num= 10;
    		break;
    	case 'L':
    		num= 50;
    		break;
    	case 'C':
    		num= 100;
    		break;
    	case 'D':
    		num= 500;
    		break;
    	case 'M':
    		num= 1000;
    		break;
	}
	return num;
}
int romanToInt(string s) {
	int result= 0;
	for (int i= s.size()-1; i>= 0; i--) {
		if (i == 0) {
			result = result + getNum(s[i]);
			return result;
		}
		if (getNum(s[i]) > getNum(s[i-1])) {
			result = result + getNum(s[i])-getNum(s[i-1]);
			i--;
		} else {
			result = result + getNum(s[i]);
		}
	}
}
int main() {
	string str;
	while (1) {
		cin>> str;
		cout<< romanToInt(str)<< endl;
	}
}
