using namespace std;

#include <vector>

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            int value = temperatures[i];
            int aux = i + 1;
            while (aux < temperatures.size() && aux > i)
            {
                if (temperatures[aux] > value)
                {
                    res[i] = aux - i;
                    break;
                }
                else if (res[aux] == 0)
                {
                    break;
                }
                else
                {
                    aux += res[aux];
                }
            }
        }
        return res;
    }
};