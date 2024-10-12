class Solution {
public:

    static bool comp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), comp);
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap to track end times
    
    for (const auto& interval : intervals) {
        if (!pq.empty() && pq.top() < interval[0]) {
            pq.pop();  // The current interval can be grouped with the one ending earliest
        }
        pq.push(interval[1]);  // Add the end time of the current interval
    }
    
    return pq.size();  // The number of groups needed
}
};