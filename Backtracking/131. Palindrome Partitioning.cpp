using namespace std;

#include <vector>
#include <string>

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> curr;
        recursive(s, 0, curr, res);
        return res;
    }

private:
    bool is_palindrome(const string &s, int start, int end)
    {
        while (start < end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void recursive(const string &s, int i, vector<string> &curr, vector<vector<string>> &res)
    {
        if (i >= s.size())
        {
            res.push_back(curr);
            return;
        }
        for (int j = i; j < s.size(); j++)
        {
            if (is_palindrome(s, i, j))
            {
                curr.push_back(s.substr(i, j - i + 1));
                recursive(s, j + 1, curr, res);
                curr.pop_back();
            }
        }
    }
};
