using namespace std;

#include <unordered_set>
#include <vector>

class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> res;

        for (int i = 0; i < triplets.size() && res.size() < 3; i++) {
            const vector<int>& t = triplets[i];
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
            for (int j = 0; j < target.size(); j++) {
                if (target[j] == t[j]) res.insert(t[j]);
            }
        }
        return res.size() == target.size();
    }
};