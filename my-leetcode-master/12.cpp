#include<iostream>
using namespace std;
string intToRoman(int num) {
        string ans[4][10]= {
        	{"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM"}
		};
		string result= "";
		result+= ans[3][num/1000%10];
		result+= ans[2][num/100%10];
		result+= ans[1][num/10%10];
		result+= ans[0][num/1%10];
		return result;
}
int main() {
	int num;
	while (1) {
		cin>> num;
		cout<< intToRoman(num)<< endl;
	}
}

