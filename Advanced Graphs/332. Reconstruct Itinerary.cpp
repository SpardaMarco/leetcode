using namespace std;

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        vector<string> res;

        for (vector<string>& t : tickets) {
            adj[t[0]].push_back(t[1]);
        }

        for (pair<const string, vector<string>>& p : adj) {
            sort(p.second.begin(), p.second.end());
        }

        dfs(adj, res, "JFK");
        reverse(res.begin(), res.end());

        if (res.size() != tickets.size() + 1) return {};
        return res;
    }

   private:
    void dfs(unordered_map<string, vector<string>>& adj, vector<string>& res, const string& curr) {
        if (adj.find(curr) != adj.end()) {
            while (!adj[curr].empty()) {
                string next = adj[curr][0];
                adj[curr].erase(adj[curr].begin());
                dfs(adj, res, next);
            }
        }
        res.push_back(curr);
    }
};