using namespace std;

#include <queue>
#include <set>
#include <vector>

class Solution {
   public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
        set<pair<int, int>> visit;
        heap.push({grid[0][0], {0, 0}});
        pair<int, int> target = {grid.size(), grid.size()};
        pair<int, int> aux[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!heap.empty()) {
            pair<int, pair<int, int>> curr = heap.top();
            heap.pop();

            if (visit.count(curr.second))
                continue;
            else if (curr.second == target) {
                return curr.first;
            }

            visit.insert(curr.second);
            for (int i = 0; i < 4; ++i) {
                pair<int, int> next = {curr.second.first + aux[i].first, curr.second.second + aux[i].second};
                if (!visit.count(next) && next.first >= 0 && next.first < grid.size() && next.second >= 0 && next.second < grid.size()) {
                    heap.push({max(curr.first, grid[next.first][next.second]), {next.first, next.second}});
                }
            }
        }
        return -1;
    }
};