class Solution {
public:
	int repeatedStringMatch(string A, string B) {
		int count = 1;
		string temp = A;
		while (temp.size() < B.size()) {
			temp += A;
			count++;
		}
		if (temp.find(B)!= string::npos) return count;
		temp += A;
		if (temp.find(B)!= string::npos) return count + 1;
		else return -1;
	}
};