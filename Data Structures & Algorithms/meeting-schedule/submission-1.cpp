/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Sort by start time
        sort(intervals.begin(), intervals.end(), 
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });
        
        // Check for overlaps
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start < intervals[i-1].end) {
                return false; // conflict found
            }
        }
        return true; // no conflicts
    }
};
