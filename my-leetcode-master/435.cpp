/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	static int cmp(Interval &x, Interval &y) {
		return x.end < y.end;
	}
	int eraseOverlapIntervals(vector<Interval>& intervals) {
		if (intervals.size() == 0 || intervals.size() == 1) return 0;
		sort(intervals.begin(), intervals.end(), cmp);
		int count = 1, temp = intervals[0].end;
		for (int i = 1; i < intervals.size(); i++) {
			if (intervals[i].start >= temp) {
				count++;
				temp = intervals[i].end;
			}
		}
		return intervals.size() - count;
	}
};