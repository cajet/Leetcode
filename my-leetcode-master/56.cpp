/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool com(const Interval& i1, const Interval& i2) {
  return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
      vector<Interval> ans;
      if (intervals.size()==0)
        return ans;
      sort(intervals.begin(), intervals.end(), com);

      ans.push_back(intervals[0]);
      for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start <= (*(--ans.end())).end) {
          if (intervals[i].end > (*(--ans.end())).end)
            (*(--ans.end())).end = intervals[i].end;
        } else {
          ans.push_back(intervals[i]);
        }
      }
      return ans;
    }
};