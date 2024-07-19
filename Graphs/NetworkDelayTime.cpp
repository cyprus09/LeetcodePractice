#include <vector>
#include <unordered_map>

using namespace std;

// djikstra algorithm
class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto &time : times)
    {
      int source = time[0];
      int destination = time[1];
      int timeToReach = time[2];

      adj[source].push_back(make_pair(destination, timeToReach));
    }

    vector<int> signalTime(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    signalTime[k] = 0;
    pq.push({0, k});

    while (!pq.empty())
    {
      int currNodeTime = pq.top().first;
      int currNode = pq.top().second;
      pq.pop();

      if (currNodeTime > signalTime[currNode])
        continue;

      for (auto &edge : adj[currNode])
      {
        int neighborNode = edge.first;
        int time = edge.second;

        if (signalTime[neighborNode] > currNodeTime + time)
        {
          signalTime[neighborNode] = currNodeTime + time;
          pq.push({signalTime[neighborNode], neighborNode});
        }
      }
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
      if (signalTime[i] == INT_MAX)
        return -1;
      result = max(signalTime[i], result);
    }

    return result;
  }
};