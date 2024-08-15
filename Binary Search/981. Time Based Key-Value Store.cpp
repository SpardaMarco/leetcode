using namespace std;

#include <string>
#include <unordered_map>
#include <vector>

class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> time_map;
    string bs(vector<pair<int, string>> &pairs, int timestamp)
    {
        int left = 0;
        int right = pairs.size() - 1;

        while (left < right)
        {
            int mid = left + (((right - left) + 1) / 2);

            if (pairs[mid].first <= timestamp)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return pairs[left].second;
    }

public:
    TimeMap()
    {
        time_map.clear();
    }

    void set(string key, string value, int timestamp)
    {
        if (time_map.find(key) == time_map.end())
        {
            time_map[key] = vector<pair<int, string>>();
        }
        time_map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (time_map.find(key) == time_map.end())
            return "";
        if (time_map[key][0].first > timestamp)
            return "";
        return bs(time_map[key], timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */