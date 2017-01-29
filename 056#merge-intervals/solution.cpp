/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
class IntervalComparison {
public:
    bool operator() (Interval &i1, Interval &i2) {
        if (i1.end != i2.end)
            return i1.end < i2.end;
        else
            return i1.start < i2.start;
    }
};
 
class Solution {
public:

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        int i;
        
        if (intervals.size() == 0)
            return result;
        
        sort(intervals.begin(), intervals.end(), IntervalComparison());
        for (i = 0; i < intervals.size(); i++) {
            if (i == 0 || intervals[i - 1].start >= intervals[i].start && intervals[i - 1].end <= intervals[i].end)
                continue;
            else if (i > 0 && intervals[i - 1].end >= intervals[i].start)
                intervals[i] = Interval(min(intervals[i].start, intervals[i - 1].start), max(intervals[i].end, intervals[i - 1].end));
            else {
                for (int j = 0; j < result.size(); j++) {
                    if (result[j].start >= intervals[i - 1].start && result[j].end <= intervals[i - 1].end) {
                        result.erase(result.begin() + j);
                        j--;
                    }
                    else if (result[j].end >= intervals[i - 1].start) {
                        intervals[i - 1] = Interval(min(result[j].start, intervals[i - 1].start), max(result[j].end, intervals[i - 1].end));
                        result.erase(result.begin() + j);
                        j--;
                    }
                }
                result.push_back(intervals[i - 1]);
            }
        }
        if (i == intervals.size()) {
            for (int j = 0; j < result.size(); j++) {
                if (result[j].start >= intervals[i - 1].start && result[j].end <= intervals[i - 1].end) {
                    result.erase(result.begin() + j);
                    j--;
                }
                else if (result[j].end >= intervals[i - 1].start) {
                    intervals[i - 1] = Interval(min(result[j].start, intervals[i - 1].start), max(result[j].end, intervals[i - 1].end));
                    result.erase(result.begin() + j);
                    j--;
                }
            }
            result.push_back(intervals[i - 1]);
        }
        return result;
    }
};