#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s) {
    	int length= s.size();
    	stack<char> sta;
    	for (int i= 0; i< length; i++) {
    		if (sta.empty() || s[i] == '[' || s[i] == '(' || s[i] == '{') {
    			sta.push(s[i]);
			} else if ((s[i] == ')' && sta.top() == '(')||(s[i] == ']' && sta.top() == '[')||(s[i] == '}' && sta.top() == '{')) {
				sta.pop();
			} else {
				sta.push(s[i]);
			}
		}
		if (sta.empty()) return true;
		else return false;
}
int main() {
	string s;
	while (1) {
		cin >> s;
		cout<< isValid(s)<< endl;
	}
}
