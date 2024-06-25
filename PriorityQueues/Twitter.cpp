#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter
{
private:
    // for users and tweet
    vector<pair<int, int>> posts;
    // for users and their followers
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        int count = 10;
        vector<int> result;

        for (int i = posts.size() - 1; i >= 0; i--)
        {
            if (count == 0)
                break;

            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> following = followMap[userId];

            if (following.find(followingId) != following.end() ||
                followingId == userId)
            {
                result.push_back(tweetId);
                count--;
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId)
    {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followMap[followerId].erase(followeeId);
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