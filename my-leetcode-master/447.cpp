class Solution {
public:
	int distance(pair<int, int> &a, pair<int, int> &b)
	{
		int x = (a.first - b.first)*(a.first - b.first);
		int y = (a.second - b.second)*(a.second - b.second);
		return x + y;
	}
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		if (points.size() <= 2) return 0;
		map<int, int>m;
		int count = 0;
		for (int i = 0; i < points.size(); i++) {
            
			for (int j = 0; j < points.size(); j++) {
				if (i != j ) {
					m[distance(points[i], points[j])]++;
				}
			}
			for (auto element : m) {
				if (element.second >= 2) {
					count = count + element.second*(element.second - 1);
				}
			}
            m.clear();
		}
		return count;
	}
};