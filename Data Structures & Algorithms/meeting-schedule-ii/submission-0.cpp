/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort by start time
        sort(intervals.begin(), intervals.end(), 
             [](const Interval &a, const Interval &b) {
                 return a.start < b.start;
             });

        // Min-heap for meeting end times
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (auto &meeting : intervals) {
            // If earliest meeting ended before current starts → reuse room
            if (!minHeap.empty() && minHeap.top() <= meeting.start) {
                minHeap.pop();
            }
            // Allocate room for current meeting
            minHeap.push(meeting.end);
        }

        // Heap size = number of rooms required
        return minHeap.size();
    }
};
