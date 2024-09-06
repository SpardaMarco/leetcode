using namespace std;

#include <unordered_set>

class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> repeated;
        while (n != 1) {
            if (repeated.count(n)) {
                return false;
            }
            repeated.insert(n);
            n = nextHappy(n);
        }
        return true;
    }

   private:
    int nextHappy(int n) {
        int res = 0;
        while (n != 0) {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
};