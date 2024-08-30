using namespace std;

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() > 0 && hand.size() % groupSize != 0) return false;
        unordered_map<int, int> map;

        for (const int& n : hand) map[n]++;

        sort(hand.begin(), hand.end());

        for (int i = 0; i < hand.size(); i++) {
            int num = hand[i];
            if (!map[num]) continue;
            map[num]--;
            for (int j = 1; j < groupSize; j++) {
                if (map.find(num + j) == map.end() || !map[num + j]) return false;
                map[num + j]--;
            }
        }

        return true;
    }
};