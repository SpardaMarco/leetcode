using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct Comp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return b.first < a.first;
    };
};

class Twitter
{
private:
    vector<vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    int count = 0;

public:
    Twitter()
    {
        tweets = vector<vector<pair<int, int>>>(500);
        follows.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({count++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> q;
        vector<int> res;
        vector<vector<pair<int, int>>> tweets_of_followed;
        for (int user : follows[userId])
            tweets_of_followed.push_back(tweets[user]);
        tweets_of_followed.push_back(tweets[userId]);

        while (!tweets_of_followed.empty())
        {
            for (int i = 0; i < tweets_of_followed.size(); i++)
            {
                vector<pair<int, int>> &v = tweets_of_followed[i];
                if (v.empty())
                {
                    tweets_of_followed.erase(tweets_of_followed.begin() + i);
                    i--;
                    continue;
                }
                pair<int, int> value = v[v.size() - 1];
                q.push(value);
                if (q.size() <= 10 || q.top().first != value.first)
                {
                    v.pop_back();
                    if (q.size() > 10)
                        q.pop();
                    if (v.empty())
                    {
                        tweets_of_followed.erase(tweets_of_followed.begin() + i);
                        i--;
                    }
                }
                else
                {
                    q.pop();
                    tweets_of_followed.erase(tweets_of_followed.begin() + i);
                    i--;
                }
            }
        }

        while (!q.empty())
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return vector<int>(res.rbegin(), res.rend());
    }

    void follow(int followerId, int followeeId)
    {
        if (follows.find(followerId) == follows.end())
            follows[followerId] = unordered_set<int>();
        follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */