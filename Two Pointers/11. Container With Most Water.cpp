using namespace std;

#include <vector>

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while (i < j)
        {
            int area = min(height[i], height[j]) * (j - i);
            if (area > res)
                res = area;
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};