/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
public class Solution {
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
    List<Interval> result = new ArrayList<>();
    if (intervals == null || newInterval == null) return result;
    int iStart = findStartPos(intervals, newInterval.start);
    int iEnd = findEndPos(intervals, newInterval.end);
    if (iStart > 0 && intervals.get(iStart - 1).end >= newInterval.start) iStart--;
    if (iEnd == intervals.size() || intervals.get(iEnd).start > newInterval.end) iEnd--;
    
    //If not in the corner cases, this condition should apply.
    if (iStart <= iEnd) {
        newInterval = new Interval(Math.min(newInterval.start, intervals.get(iStart).start),Math.max(newInterval.end, intervals.get(iEnd).end));
    }

    int i = 0;
    while (i < iStart) result.add(intervals.get(i++));
    result.add(newInterval);
    i = iEnd + 1;
    while (i < intervals.size()) result.add(intervals.get(i++));
    return result;
}

private int findStartPos(List<Interval> intervals, int value) {
    int l = 0, r = intervals.size() - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (intervals.get(m).start == value) return m;
        else if (intervals.get(m).start < value) l = m + 1;
        else r = m - 1;
    }
    return l;
}

private int findEndPos(List<Interval> intervals, int value) {
    int l = 0, r = intervals.size() - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (intervals.get(m).end == value) return m;
        else if (intervals.get(m).end < value) l = m + 1;
        else r = m - 1;
    }
    return l;
}
}