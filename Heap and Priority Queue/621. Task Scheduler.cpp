using namespace std;

#include <vector>
#include <queue>
#include <unordered_map>
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> v(26, 0);
        for (char c : tasks)
            v[c - 'A']++;
        priority_queue<int> q;
        for (int num : v)
            if (num)
                q.push(num);
        int res = 0;
        unordered_map<int, int> m;

        while (!m.empty() || !q.empty())
        {
            if (m.find(res) != m.end())
            {
                q.push(m[res]);
                m.erase(res);
            }
            res++;
            if (!q.empty())
            {
                int count = q.top() - 1;
                q.pop();
                if (count)
                    m[res + n] = count;
            }
        }
        return res;
    }
};