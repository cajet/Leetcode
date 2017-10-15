class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		map<char, int> m;
		int max = 0;
		int max_count = 0;
		for (int i = 0; i < tasks.size(); i++) {
			m[tasks[i]]++;
			if (max < m[tasks[i]]) max = m[tasks[i]];
		}
		map<char, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second == max) max_count++;
		}
		return tasks.size() > (n + 1)*(max - 1) + max_count ? tasks.size() : (n + 1)*(max - 1) + max_count;
	}
};