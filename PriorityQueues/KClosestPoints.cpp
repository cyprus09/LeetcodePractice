#include <queue>
#include <vector>
#include <cmath>

using namespace std;

// slightly complex but would impress the interview if implemented properly
struct Comparator
{
    bool operator()(const pair<vector<int>, int> &lhs, const pair<vector<int>, int> &rhs) const
    {
        return pow(lhs.first[0], 2) + pow(lhs.first[1], 2) > pow(rhs.first[0], 2) + pow(rhs.first[1], 2);
    }
};

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<vector<int>, int>, vector<pair<vector<int>, int>>, Comparator> pq;
        vector<vector<int>> answer;

        for (auto &it : points)
        {
            int distanceSquared = pow(it[0], 2) + pow(it[1], 2);
            pq.push({it, distanceSquared});
        }

        while (k-- && !pq.empty())
        {
            vector<int> ans = pq.top().first;
            answer.push_back(ans);
            pq.pop();
        }

        return answer;
    }
};

// following also works
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, vector<int>>> pq;
        for (auto const &point : points)
        {
            double distance = pow(point[0], 2) + pow(point[1], 2);
            pq.push({distance, point});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> answer;
        while (!pq.empty())
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
