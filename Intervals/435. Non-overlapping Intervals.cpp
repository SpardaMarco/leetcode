using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        int res = 0;
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> curr = intervals[i];

            if (curr[0] >= end)
            {
                end = curr[1];
            }
            else
            {
                res++;
                end = min(end, curr[1]);
            }
        }
        return res;
    }
};