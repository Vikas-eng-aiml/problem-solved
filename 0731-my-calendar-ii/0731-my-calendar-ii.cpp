class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        
        for (auto& interval : overlaps) {
            if (max(interval.first, start) < min(interval.second, end)) {
               
                return false;
            }
        }

       
        for (auto& interval : bookings) {
            int s = max(interval.first, start);
            int e = min(interval.second, end);
            if (s < e) {
                overlaps.push_back({s, e});
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */