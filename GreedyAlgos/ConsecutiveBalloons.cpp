#include <vector>

using namespace std;

class Solution
{
public:
  int minCost(string colors, vector<int> &neededTime)
  {
    int totalTime = 0;
    int n = neededTime.size();

    for (int i = 1; i < n; i++)
    {
      if (colors[i] == colors[i - 1])
      {
        totalTime += min(neededTime[i], neededTime[i - 1]);
        neededTime[i] = max(neededTime[i - 1], neededTime[i]);
      }
    }

    return totalTime;
  }
};

// dp approach altough can be solved in a greedy way
class Solution
{
public:
  int minCost(string colors, vector<int> &neededTime)
  {
    int n = neededTime.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
      if (colors[i] == colors[i - 1])
      {
        dp[i] = dp[i - 1] + min(neededTime[i], neededTime[i - 1]);
        // store needed time for future comparisions when we have multiple consecutive
        neededTime[i] = max(neededTime[i], neededTime[i - 1]);
      }
      else
        dp[i] = dp[i - 1];
    }

    return dp[n - 1];
  }
};