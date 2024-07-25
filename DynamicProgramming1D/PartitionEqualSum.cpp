#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;
    for (int num : nums)
      sum += num;

    if (sum % 2 != 0)
      return false;

    int sumToEqual = sum / 2;

    vector<bool> dp(sumToEqual + 1, false);
    dp[0] = true;

    for (int num : nums)
    {
      for (int i = sumToEqual; i >= num; i--)
      {
        dp[i] = dp[i] || dp[i - num];
      }
    }

    return dp[sumToEqual];
  }
};

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;
    for (int num : nums)
    {
      sum += num;
    }
    if (sum % 2 != 0)
    {
      return false;
    }
    sum /= 2;

    unordered_set<int> dp;
    dp.insert(0);

    for (int num : nums)
    {
      unordered_set<int> dpNext;
      for (auto it = dp.begin(); it != dp.end(); it++)
      {
        if (*it + num == sum)
        {
          return true;
        }
        dpNext.insert(*it + num);
        dpNext.insert(*it);
      }
      dp = dpNext;
    }

    return false;
  }
};