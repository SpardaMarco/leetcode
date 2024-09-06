using namespace std;

#include <string>
#include <vector>

class Solution {
   public:
    bool isMatch(string s, string p) {
        vector<vector<short>> cache(s.size() + 1, vector<short>(p.size() + 1, -1));
        return dfs(0, 0, s, p, cache);
    }

   private:
    bool dfs(int is, int ip, string& s, string& p, vector<vector<short>>& cache) {
        if (cache[is][ip] != -1) {
            return cache[is][ip] == 1 ? true : false;
        }

        if (is >= s.size() && ip >= p.size()) {
            return true;
        }

        if (ip >= p.size()) {
            return false;
        }

        bool res = is < s.size() && (s[is] == p[ip] or p[ip] == '.');
        if ((ip + 1) < p.size() && p[ip + 1] == '*') {
            cache[is][ip] = (dfs(is, ip + 2, s, p, cache) || (res && dfs(is + 1, ip, s, p, cache))) ? 1 : 0;
            return cache[is][ip];
        }

        if (res) {
            cache[is][ip] = dfs(is + 1, ip + 1, s, p, cache);
            return cache[is][ip];
        }
        cache[is][ip] = false;
        return false;
    }
};