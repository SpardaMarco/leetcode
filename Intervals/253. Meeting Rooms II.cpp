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
    int minMeetingRooms(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return 0;

        vector<int> starts;
        vector<int> ends;

        for (const Interval &i : intervals)
        {
            starts.push_back(i.start);
            ends.push_back(i.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int min_rooms = 0;
        int curr = 0;
        int s = 0;
        int e = 0;
        while (s < intervals.size())
        {
            if (starts[s] < ends[e])
            {
                ++curr;
                ++s;
                min_rooms = max(min_rooms, curr);
            }
            else
            {
                --curr;
                ++e;
            }
        }
        return min_rooms;
    }
};
