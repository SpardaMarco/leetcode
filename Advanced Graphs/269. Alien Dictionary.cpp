using namespace std;

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visit;
    string result;
    string foreignDictionary(vector<string>& words) {
        for (const string& w : words) {
            for (const char& c : w) adj[c];
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            int min_len = min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, min_len) == w2.substr(0, min_len)) return "";
            for (int j = 0; j < min_len; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        for (const pair<const char, unordered_set<char>>& p : adj) {
            if (dfs(p.first)) return "";
        }
        reverse(result.begin(), result.end());
        return result;
    }

   private:
    bool dfs(char ch) {
        if (visit.count(ch)) return visit[ch];
        visit[ch] = true;
        for (const char& next : adj[ch]) {
            if (dfs(next)) {
                return true;
            }
        }
        visit[ch] = false;
        result.push_back(ch);
        return false;
    }
};
