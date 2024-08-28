using namespace std;

#include <vector>

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        if (intervals.empty())
        {
            res.push_back(newInterval);
            return res;
        }

        vector<int> curr = newInterval;
        bool insert = false;
        bool done = false;

        for (int i = 0; i < intervals.size(); i++)
        {
            vector<int> interval = intervals[i];
            if (!done && ((interval[1] >= curr[0] && interval[1] <= curr[1]) || (interval[0] >= curr[0] && interval[0] <= curr[1]) || (interval[1] >= curr[1] && interval[0] <= curr[0])))
            {
                curr[0] = min(interval[0], curr[0]);
                curr[1] = max(interval[1], curr[1]);
                insert = true;
            }
            else
            {
                if (insert)
                {
                    res.push_back(curr);
                    done = true;
                    insert = false;
                }
                if (!done && interval[0] > curr[1])
                {
                    res.push_back(curr);
                    done = true;
                }
                res.push_back(interval);
            }
        }

        if (!done)
            res.push_back(curr);

        return res;
    }
};