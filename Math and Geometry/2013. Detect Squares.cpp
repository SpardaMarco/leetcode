using namespace std;

#include <algorithm>
#include <unordered_map>
#include <vector>

class DetectSquares {
   public:
    unordered_map<long, int> ptsCount;
    vector<vector<int>> pts;
    DetectSquares() {
    }

    void add(vector<int> point) {
        long key = static_cast<long>(point[0]) << 32 | static_cast<long>(point[1]);
        ptsCount[key]++;
        pts.push_back(point);
    }

    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];
        for (const vector<int>& pt : pts) {
            int x = pt[0], y = pt[1];
            if (abs(x - px) != abs(y - py) || x == px || y == py) continue;
            long key1 = static_cast<long>(x) << 32 | static_cast<long>(py);
            long key2 = static_cast<long>(px) << 32 | static_cast<long>(y);

            res += ptsCount[key1] * ptsCount[key2];
        }
        return res;
    }
};