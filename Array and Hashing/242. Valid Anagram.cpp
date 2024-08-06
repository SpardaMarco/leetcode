#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int array[26] = {0};
        size_t size = s.length();

        if (size != t.length())
            return false;
        for (int i = 0; i < size; i++)
        {
            int s_index = s[i] - 'a';
            int t_index = t[i] - 'a';
            array[s_index]++;
            array[t_index]--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (array[i] != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "rat";
    string t2 = "car";

    Solution solver = Solution();

    cout << "Test 1 - Expected: " << true << " Received: " << solver.isAnagram(s1, t1) << endl;
    cout << "Test 2 - Expected: " << false << " Received: " << solver.isAnagram(s2, t2) << endl;
    return 0;
}