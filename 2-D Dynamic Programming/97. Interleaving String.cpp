using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        unordered_map<int, bool> cache;
        return dfs(0, 0, 0, s1, s2, s3, cache);
    }

   private:
    bool dfs(int i1, int i2, int i3, string& s1, string& s2, string& s3, unordered_map<int, bool>& cache) {
        if (i3 == s3.size()) return true;
        int key = i1 << 16 | i2 << 8 | i3;
        if (cache.find(key) != cache.end()) {
            return cache[key];
        }

        bool res = (s1[i1] == s3[i3] && dfs(i1 + 1, i2, i3 + 1, s1, s2, s3, cache)) || (s2[i2] == s3[i3] && dfs(i1, i2 + 1, i3 + 1, s1, s2, s3, cache));
        cache[key] = res;
        return res;
    }
};