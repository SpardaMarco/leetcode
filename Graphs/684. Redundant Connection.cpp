using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> rep(edges.size() + 1);
        vector<int> rank(edges.size() + 1, 1);
        for (int i = 0; i < rep.size(); i++)
            rep[i] = i;

        for (vector<int> &p : edges)
        {
            if (!union_func(rep, rank, p[0], p[1]))
                return {p[0], p[1]};
        }
        return {};
    }

private:
    int find(int n, vector<int> &rep)
    {
        if (rep[n] != n)
        {
            rep[n] = find(rep[n], rep);
        }
        return rep[n];
    }

    bool union_func(vector<int> &rep, vector<int> &rank, int i, int j)
    {
        int i_rep = find(i, rep);
        int j_rep = find(j, rep);

        if (i_rep == j_rep)
            return false;

        int i_size = rank[i_rep];
        int j_size = rank[j_rep];

        if (i_size < j_size)
        {
            rep[i_rep] = j_rep;
            rank[j_rep] += i_size;
        }

        else
        {
            rep[j_rep] = i_rep;
            rank[i_rep] += j_size;
        }

        return true;
    }
};