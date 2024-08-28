using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs)
             { return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] < rhs[1]); });

        int new_start = intervals[0][0];
        int new_end = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> curr = intervals[i];
            if (new_end < curr[0])
            {
                res.push_back({new_start, new_end});
                new_start = curr[0];
                new_end = curr[1];
            }
            else
            {
                new_end = max(curr[1], new_end);
            }
        }

        res.push_back({new_start, new_end});
        return res;
    }
};