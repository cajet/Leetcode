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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> m;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            m[intervals[i].start] = i;
        for (auto in : intervals) {
            auto itr = m.lower_bound(in.end);
            if (itr == m.end()) res.push_back(-1);
            else res.push_back(itr->second);
        }
        return res;
    }
};