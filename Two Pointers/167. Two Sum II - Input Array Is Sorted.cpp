using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;
        int res = numbers[i] + numbers[j];

        while (res != target)
        {
            if (res > target)
            {
                j--;
                res = numbers[i] + numbers[j];
            }
            else
            {
                i++;
                res = numbers[i] + numbers[j];
            }
        }

        return vector<int>({i + 1, j + 1});
    }
};