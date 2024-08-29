using namespace std;

#include <vector>
#include <algorithm>
#include <queue>
#include <map>

class Solution
{
public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        sort(intervals.begin(), intervals.end());
        vector<int> sorted_queries(queries);
        sort(sorted_queries.begin(), sorted_queries.end());
        map<int, int> aux;
        auto cmp = [](const vector<int> &a, const vector<int> &b)
        {
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp);
        vector<int> res;

        int i = 0;
        for (int q : sorted_queries)
        {
            while (i < intervals.size() && intervals[i][0] <= q)
            {
                min_heap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                ++i;
            }

            while (!min_heap.empty() && min_heap.top()[1] < q)
            {
                min_heap.pop();
            }

            aux[q] = min_heap.empty() ? -1 : min_heap.top()[0];
        }

        for (int q : queries)
        {
            res.push_back(aux[q]);
        }
        return res;
    }
};