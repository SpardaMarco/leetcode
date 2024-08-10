using namespace std;

#include <vector>
#include <deque>

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int size = nums.size();
        vector<int> res(size - k + 1);
        deque<int> order;

        int l = 0, r = 0;

        while (r < size)
        {
            while (!order.empty() && nums[r] > nums[order.back()])
            {
                order.pop_back();
            }
            order.push_back(r);

            if (l > order.front())
                order.pop_front();

            r++;

            if (r >= k)
            {
                res[l] = nums[order.front()];
                l++;
            }
        }
        return res;
    }
};