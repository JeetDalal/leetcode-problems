#include <vector>
using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> events; // Store events as pairs of (start, end)

    MyCalendar() {
        // No need for initialization here
    }
    
    bool book(int start, int end) {
        // Check for overlaps with existing events
        for (const auto& event : events) {
            // Check if the new event overlaps with the existing event
            if (start < event.second && end > event.first) {
                return false; // Overlap detected
            }
        }
        // If no overlap, add the new event
        events.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */