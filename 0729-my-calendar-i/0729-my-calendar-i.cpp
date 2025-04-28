class MyCalendar {
private:
    vector<pair<int, int>> bookings;

public:
    MyCalendar() {
        // Constructor
    }

    bool book(int startTime, int endTime) {
        for (auto& event : bookings) {
          
            if (max(event.first, startTime) < min(event.second, endTime)) {
              
                return false;
            }
        }
      
        bookings.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */