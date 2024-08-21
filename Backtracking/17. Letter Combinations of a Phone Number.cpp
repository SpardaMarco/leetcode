using namespace std;

#include <vector>
#include <string>
#include <unordered_map>

class Solution
{

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;
        unordered_map<char, string> digit_to_char = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "qprs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        recursive(digits, 0, "", digit_to_char, res);
        return res;
    }

private:
    void recursive(string digits, int i, string curr, unordered_map<char, string> &digit_to_char, vector<string> &res)
    {
        if (i >= digits.size())
        {
            res.push_back(curr);
            return;
        }

        for (char c : digit_to_char[digits[i]])
        {
            recursive(digits, i + 1, curr + c, digit_to_char, res);
        }
    }
};