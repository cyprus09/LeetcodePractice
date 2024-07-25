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