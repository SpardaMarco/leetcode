using namespace std;

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        unordered_map<string, vector<string>> aux;
        wordList.push_back(beginWord);
        for (string &w : wordList)
        {
            for (int i = 0; i < w.size(); i++)
            {
                string pattern = w.substr(0, i) + "*" + w.substr(i + 1);
                aux[pattern].push_back(w);
            }
        }

        unordered_set<string> visited{beginWord};
        queue<string> q;
        int res = 1;
        q.push(beginWord);

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string word = q.front();
                q.pop();
                if (word == endWord)
                    return res;
                int w_size = word.size();
                for (int j = 0; j < w_size; j++)
                {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for (string &wo : aux[pattern])
                    {
                        if (!visited.count(wo))
                        {
                            visited.insert(wo);
                            q.push(wo);
                        }
                    }
                }
            }
            res++;
        }

        return 0;
    }
};