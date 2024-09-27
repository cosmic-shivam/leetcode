class MyCalendarTwo {
public:
    vector<pair<int, int>> calendar;
    vector<pair<int, int>> overlaps;

    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // Check for triple booking by comparing with the overlaps list.
        for (auto& overlap : overlaps) {
            if (max(start, overlap.first) < min(end, overlap.second)) {
                return false; // Triple booking found
            }
        }
        
        // Check for overlaps with existing bookings in the calendar
        for (auto& event : calendar) {
            if (max(start, event.first) < min(end, event.second)) {
                // If there is an overlap, record it in the overlaps list
                overlaps.push_back({max(start, event.first), min(end, event.second)});
            }
        }
        
        // No triple booking, so add the event to the calendar
        calendar.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */