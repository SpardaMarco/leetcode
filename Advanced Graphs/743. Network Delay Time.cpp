using namespace std;

#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_set<int> visit;
        vector<vector<pair<int, int>>> adj(n + 1);

        for (vector<int>& e : times) {
            adj[e[0]].push_back({e[2], e[1]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, k});

        int res = 0;
        while (!minHeap.empty()) {
            pair<int, int> edge = minHeap.top();
            minHeap.pop();
            if (visit.count(edge.second)) continue;
            visit.insert(edge.second);

            res = edge.first;
            for (pair<int, int>& e : adj[edge.second]) {
                if (!visit.count(e.second))
                    minHeap.push({res + e.first, e.second});
            }
        }
        return visit.size() == n ? res : -1;
    }
};