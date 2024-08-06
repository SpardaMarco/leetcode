using namespace std;

#include <vector>
#include <string>
/*
#include <set>

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        set<string> aux = {"()"};

        for (int i = 2; i <= n; i++)
        {
            set<string> new_aux;
            for (string s : aux)
            {
                size_t pos = 0;
                size_t index = s.find(')', pos);
                while (index != string::npos)
                {
                    new_aux.insert(s.substr(0, index) + "()" + s.substr(index, s.size() - index)); // "01234"
                    pos = index + 1;
                    index = s.find(')', pos);
                }
                new_aux.insert(s.append("()"));
            }
            aux = new_aux;
        }

        return vector(aux.begin(), aux.end());
    }
};
*/

class Solution
{
private:
    void backtrack(int n, int left_count, int right_count, string current, vector<string> &res)
    {
        if (left_count == right_count && left_count == n)
        {
            res.push_back(current);
            return;
        }

        if (left_count < n)
        {
            backtrack(n, left_count + 1, right_count, current + '(', res);
        }

        if (left_count > right_count)
        {
            backtrack(n, left_count, right_count + 1, current + ')', res);
        }
        return;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        backtrack(n, 0, 0, "", res);
        return res;
    }
};
