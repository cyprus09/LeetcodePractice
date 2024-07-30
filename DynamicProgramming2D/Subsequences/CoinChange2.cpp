#include <vector>

using namespace std;

class Solution
{
private:
  int changeHelper(int amount, vector<int> &coins, vector<vector<int>> &dp,
                   int index)
  {
    if (index == 0)
      return amount % coins[0] == 0;

    if (dp[index][amount] != -1)
      return dp[index][amount];

    int notTaken = changeHelper(amount, coins, dp, index - 1);
    int taken = 0;
    if (coins[index] <= amount)
      taken = changeHelper(amount - coins[index], coins, dp, index);

    return dp[index][amount] = (taken + notTaken);
  }

public:
  int change(int amount, vector<int> &coins)
  {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    return changeHelper(amount, coins, dp, n - 1);
  }
};