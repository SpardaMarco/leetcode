using namespace std;

#include <math.h>

#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int res = 0;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int distance = abs(x - x2) + abs(y - y2);
                adj[i].push_back({distance, j});
                adj[j].push_back({distance, i});
            }
        }

        unordered_set<int> visit;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});

        while (visit.size() < points.size()) {
            pair<int, int> p = minHeap.top();
            minHeap.pop();
            if (visit.count(p.second)) continue;
            res += p.first;
            for (pair<int, int>& pair : adj[p.second]) {
                minHeap.push(pair);
            }

            visit.insert(p.second);
        }

        return res;
    }
};