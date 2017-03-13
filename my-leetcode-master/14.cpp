#include<iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int num_of_str = strs.size();
    if (num_of_str == 0) return "";
    if (num_of_str == 1) return strs[0];
    int first_str_length= strs[0].size();
    string result= "";
    for (int i= 0; i< first_str_length; i++) {
    	for (int j= 1; j< num_of_str; j++) {
    		if (strs[j][i] != strs[0][i] || i>= strs[j].size()) {
    			return result;
			} else {
				if (j == num_of_str-1) result+= strs[0][i];
			}
		}
	}
	return result;
}
int main() {
	vector<string> strs;
	string s;
	for (int i= 0; i< 4; i++) {
		cin>> s;
		strs.push_back(s);
	}
	cout<< longestCommonPrefix(strs)<< endl;
}
