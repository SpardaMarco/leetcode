using namespace std;
#include <vector>

class Solution
{
private:
    bool binarySearch(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int midpoint = left + ((right - left) / 2);
            if (nums[midpoint] > target)
            {
                right = midpoint - 1;
            }
            else if (nums[midpoint] < target)
            {
                left = midpoint + 1;
            }
            else
                return true;
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int ll = 0;
        int ul = matrix.size() - 1;
        if (matrix.size() == 1)
            return binarySearch(matrix[0], target);
        if (matrix[ul][0] <= target)
            return binarySearch(matrix[ul], target);

        while (ll < ul)
        {
            int midpoint = ll + ((ul - ll) / 2);
            if (matrix[midpoint][0] <= target)
                ll = midpoint + 1;
            else
                ul = midpoint;
        }
        if (ll == 0)
            return false;

        return binarySearch(matrix[ll - 1], target);
    }
};