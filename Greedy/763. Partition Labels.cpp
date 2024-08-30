using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        unordered_map<char, int> pos;
        for (int i = 0; i < s.size(); i++) {
            pos[s[i]] = i;
        }

        int index = 0;
        int startPos = 0;
        int targetPos = pos[s[index]];
        while (index < s.size()) {
            if (index == targetPos) {
                res.push_back(targetPos - startPos + 1);
                index++;
                startPos = index;
                if (index < s.size())
                    targetPos = pos[s[index]];
            } else {
                targetPos = max(targetPos, pos[s[index++]]);
            }
        }
        return res;
    }
};