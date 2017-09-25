vector<string> fizzBuzz(int n) {
	vector <string> v;
	char a[10];
	for (int i = 1; i <= n;  i++) {
		if (i % 3 == 0 && i % 5 == 0) {
			v.push_back("FizzBuzz");
		}
		else if (i % 3 == 0) v.push_back("Fizz");
		else if (i % 5 == 0) v.push_back("Buzz");
		else {
			/*string str;
			itoa(i, a, 10);
			str = a;
			v.push_back(str);*/
			v.push_back(to_string(i));
		}
	}
	return v;
}
/*
int main() {
	int a = 15;
	vector<string> result = fizzBuzz(a);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}
*/