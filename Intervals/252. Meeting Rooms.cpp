using namespace std;

#include <vector>
#include <algorithm>

// Definition of Interval:
class Interval
{
public:
    int start, end;
    Interval(int start, int end)
    {
        this->start = start;
        this->end = end;
    }
};

class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return true;
        sort(intervals.begin(), intervals.end(), [](const Interval &lhs, const Interval &rhs)
             { return lhs.end < rhs.end; });
        int new_end = intervals[0].end;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (new_end > intervals[i].start)
                return false;
            new_end = intervals[i].end;
        }
        return true;
    }
};
