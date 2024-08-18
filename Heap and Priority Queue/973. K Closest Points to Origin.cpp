using namespace std;

#include <vector>
#include <queue>

class Wrapper
{
public:
    Wrapper(long distance, vector<int> p) : distance(distance), p(p) {}
    long distance;
    vector<int> p;
};

struct Comp
{
    bool operator()(Wrapper a, Wrapper b) { return a.distance > b.distance; }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<Wrapper, vector<Wrapper>, Comp> q;
        vector<vector<int>> res;
        for (vector<int> p : points)
            q.push(Wrapper(p[0] * p[0] + p[1] * p[1], p));
        for (int i = 0; i < k; i++)
        {
            res.push_back(q.top().p);
            q.pop();
        }
        return res;
    }
};