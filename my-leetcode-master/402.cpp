string removeKdigits(string num, int k) {
	if (k >= num.size()) return "0";
	stack<char> s;
	s.push(num[0]);
	int i = 1;
	int count = 0;
	while (i< num.size()) {
		while (!s.empty() &&s.top() > num[i] && count< k) {
			s.pop();
			count++;
		}
		s.push(num[i]);
		i++;
	}
	while (count < k) {
		s.pop();
		count++;
	}
	string temp = "", res = "";
	while (!s.empty()) {
		temp = s.top() + temp;
		s.pop();
	}
	//cout << temp << endl;
	int j;
	for (j = 0; j < temp.length(); j++) {
		if (temp[j] != '0') {
			break;
		}
	}
	if (j == temp.length()) return "0";
	return temp.substr(j, temp.length() - j);
}