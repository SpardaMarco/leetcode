using namespace std;

#include <string>
#include <unordered_map>

class Solution {
   public:
    int numDistinct(string s, string t) {
        unordered_map<long, int> cache;
        return dfs(0, 0, s, t, cache);
    }

   private:
    int dfs(int is, int it, string& s, string& t, unordered_map<long, int>& cache) {
        if (is == s.size() && it != t.size()) {
            return 0;
        } else if (it == t.size()) {
            return 1;
        }

        long key = static_cast<long>(is) << 32 | static_cast<long>(it);
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        int res = 0;
        if (s[is] == t[it]) {
            res += dfs(is + 1, it + 1, s, t, cache);
        }
        res += dfs(is + 1, it, s, t, cache);
        cache[key] = res;
        return res;
    }
};