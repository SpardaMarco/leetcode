using namespace std;

#include <string>

class Solution {
   public:
    bool checkValidString(string s) {
        int openMin = 0;
        int openMax = 0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (c == '(') {
                ++openMin;
                ++openMax;
            } else if (c == ')') {
                --openMin;
                --openMax;
            } else {
                --openMin;
                ++openMax;
            }

            openMin = max(openMin, 0);
            if (openMax < 0) return false;
        }

        return 0 == openMin;
    }
};