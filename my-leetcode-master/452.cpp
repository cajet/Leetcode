class Solution {
public:
	static int cmp(pair<int,int>& x, pair<int, int>& y) {
		return x.second < y.second;
	}
	int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.size()== 0) return 0;
		if (points.size() == 1) return 1;
		sort(points.begin(), points.end(), cmp);
		int count = 1;
		int temp = points[0].second;
		for (int i = 1; i < points.size(); i++) {
			if (points[i].first > temp) {
				count++;
				temp = points[i].second;
			}
		}
		return count;
	}
};