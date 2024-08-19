using namespace std;

#include <vector>
#include <queue>

class MedianFinder
{
private:
    priority_queue<int> lower_heap;
    priority_queue<int, vector<int>, greater<int>> higher_heap;

    int abs(int a)
    {
        if (a < 0)
            return -a;
        return a;
    }

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        lower_heap.push(num);
        if (!higher_heap.empty())
        {
            while (lower_heap.top() > higher_heap.top())
            {
                higher_heap.push(lower_heap.top());
                lower_heap.pop();
            }
        }

        while ((int)(lower_heap.size() - higher_heap.size()) >= 2)
        {
            higher_heap.push(lower_heap.top());
            lower_heap.pop();
        }

        while ((int)(higher_heap.size() - lower_heap.size()) >= 2)
        {
            lower_heap.push(higher_heap.top());
            higher_heap.pop();
        }
    }

    double findMedian()
    {
        if (higher_heap.size() == lower_heap.size())
        {
            return (higher_heap.top() + lower_heap.top()) / 2.0;
        }
        if (higher_heap.size() > lower_heap.size())
            return higher_heap.top();
        return lower_heap.top();
    }
};