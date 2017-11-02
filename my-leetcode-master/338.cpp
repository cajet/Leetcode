class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> v;
		int temp, count;
		for (int i = 0; i <= num; i++) {
			temp = i;
			count = 0;
			if (temp == 0) {
				v.push_back(0);
				continue;
			}
			while (temp) {
				temp = temp&(temp - 1);
				count++;
			}
			v.push_back(count);
		}
		return v;
	}
};