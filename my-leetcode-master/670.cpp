class Solution {
public:
	int maximumSwap(int num) {
		vector<int> v;
		int temp = num;
		while (num) {
			v.push_back(num % 10);
			num /= 10;
		}
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) swap(v[i], v[j]);
		for (int i = 0; i < v.size(); i++) {
			int index;
			int max = v[i];
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j] >= max) {
					index = j;
					max = v[j];
				}
			}
			if (max > v[i]) {
				swap(v[index], v[i]);
				int res = 0;
				for (int k = 0; k < v.size(); k++) { 
					res = res * 10 + v[k];
				}
				return res;
			}
		}
		return temp;
	}
};
