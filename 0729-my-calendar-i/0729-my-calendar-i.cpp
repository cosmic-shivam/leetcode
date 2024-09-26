class MyCalendar {
public:
   // Store the booked intervals
    vector<pair<int, int>> bookings;
    
    MyCalendar() {
        // Constructor doesn't need to do anything
    }
    
    // Function to book an event if no overlap occurs
    bool book(int start, int end) {
        // Iterate through the existing bookings
        for (auto &booking : bookings) {
            int bookedStart = booking.first;
            int bookedEnd = booking.second;
            
            // Check if the new booking overlaps with the current booking
            if (max(bookedStart, start) < min(bookedEnd, end)) {
                return false;  // Overlap found, can't book the event
            }
        }
        
        // No overlap, add the event to bookings
        bookings.push_back({start, end});
        return true;
    }
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */