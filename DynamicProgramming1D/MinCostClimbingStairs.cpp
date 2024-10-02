#include <vector>

using namespace std;

class Solution1
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    cost.push_back(0);
    int n = cost.size();
    for (int i = n - 3; i >= 0; i--)
      cost[i] += min(cost[i + 1], cost[i + 2]);

    return min(cost[0], cost[1]);
  }
};

class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    // take two options, option1 is min cost to n - 1 + (n - 1 to n)
    // option 2 is min cost to n - 2 + (n - 2 to n)
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    // you can either start from dp[0] or dp[1] so cost will be zero for
    // these indices
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++)
    {
      int option1 = cost[i - 1] + dp[i - 1];
      int option2 = cost[i - 2] + dp[i - 2];
      dp[i] = min(option1, option2);
    }
    return dp[n];
  }
};

class Solution2
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int downOne = 0, downTwo = 0;

    for (int i = 2; i <= cost.size(); i++)
    {
      int temp = downOne;
      downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
      downTwo = temp;
    }
    return downOne;
  }
};