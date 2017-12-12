	class Solution {
	public:
		bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
			queue<int> q;
			vector<int> res;
			vector<int> rudu(numCourses, 0);
			for (int i = 0; i < prerequisites.size(); i++) {
				rudu[prerequisites[i].first]++;
			}
			for (int i = 0; i < numCourses; i++) {
				if (rudu[i] == 0) {
					q.push(i);
				}
			}
			while (!q.empty()) {
				int temp = q.front();
				q.pop();
				res.push_back(temp);
				for (int k = 0; k < prerequisites.size(); k++) {
					if ((temp == prerequisites[k].second) && (--rudu[prerequisites[k].first] == 0)) {
						q.push(prerequisites[k].first);
					}
				}
			}
			if (res.size() != numCourses) return false;
			else return true;
		}
	};