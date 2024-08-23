using namespace std;

#include <vector>

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int two_before = 0;
        int before = 0;

        for (int n : nums)
        {
            int temp = max(n + two_before, before);
            two_before = before;
            before = temp;
        }

        return before;
    }
};