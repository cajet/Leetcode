class Solution {
public:
	int calPoints(vector<string>& ops) {
		stack <int> s;
		for (int i = 0; i < ops.size(); i++) {
			if (ops[i] == "+") {
				int first = s.top();
				s.pop();
				int second = s.top();
				s.push(first);
				s.push(first + second);
			}
			else if (ops[i] == "D") {
				s.push(s.top() * 2);
			}
			else if (ops[i] == "C") {
				s.pop();
			}
			else {
				string temp = ops[i];
				int sum = 0;
				int length = temp.length();
				int tmp;
				bool flag = true;
				for (int j = 0; j < length; j++) {
					if (temp[j] == '-' ) {
						flag = false;
						continue;
					}
					tmp = temp[j] - '0';
					sum += tmp*pow(10, length - j-1);
				}
				if (flag== true) s.push(sum);
				else s.push(0 - sum);
			}
		}
		int result = 0;
		while (!s.empty()) {
			result += s.top();
			s.pop();
		}
		return result;
	}
};