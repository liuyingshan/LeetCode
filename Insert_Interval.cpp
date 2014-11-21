/*
  Given a set of non-overlapping intervals, insert a new interval into the
  intervals (merge if necessary).
  You may assume that the intervals were initially sorted according to their
  start times.

  Example 1:
  Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

  Example 2:
  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
  [1,2],[3,10],[12,16].

  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

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
    /*
     *Find the position which the newInterval inserts after.
     */
    int findInsertPos(vector<Interval> &intervals, Interval &newInterval) {
        int l = 0, r = intervals.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (newInterval.start >= intervals[mid].start) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }
        int pos = findStartPos(intervals, newInterval);
        int n = intervals.size(), i = 0;
        
        // Before newInterval inserts, the original intervals are the same as
		// before.
        for (; i<pos; i++) {
            result.push_back(intervals[i]);
        }
        
        // The newInterval does not overlap with preceding interval.
        if (result.empty() || result.back().end < newInterval.start) {
            result.push_back(newInterval);
        // The newInterval overlaps with the preceding interval.
        } else if (newInterval.end > result.back().end) {
            result.back().end = newInterval.end;
        }
        
        for (; i<n; i++) {
        	// The interval does not overlap with the preceding interval.
            if (intervals[i].start > result.back().end) {
                result.push_back(intervals[i]);
            // The interval overlap with the preceding interval.
            } else if (intervals[i].start <= result.back().end
                    && intervals[i].end > result.back().end) {
                result.back().end = intervals[i].end;
            }
        }
        
        return result;
    }
};
