/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> result;
    if (A.empty()) return result;

    // Sort intervals based on start time
    sort(A.begin(), A.end(), [](const Interval &a, const Interval &b) {
        return a.start < b.start;
    });

    // Initialize the first interval
    Interval current = A[0];

    // Iterate through the sorted intervals
    for (int i = 1; i < A.size(); ++i) {
        // If the current interval overlaps with the next interval
        if (current.end >= A[i].start) {
            // Merge the intervals
            current.end = max(current.end, A[i].end);
        } else {
            // No overlap, push the current interval to result
            result.push_back(current);
            // Move to the next interval
            current = A[i];
        }
    }

    // Don't forget to add the last interval
    result.push_back(current);

    return result;
}
