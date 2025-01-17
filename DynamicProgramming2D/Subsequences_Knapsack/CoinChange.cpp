#include <vector>

using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
      for (int j = 0; j < coins.size(); j++)
      {
        if (i - coins[j] >= 0)
          dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};

// better to remember approach and explainable
// uses target sum approach in subsequence
class Solution
{
private:
  int coinHelper(vector<int> &coins, int amount, vector<vector<int>> &dp,
                 int i)
  {
    if (i == 0)
    {
      if (amount % coins[i] != 0)
        return 1e9;
      else
        return amount / coins[i];
    }

    if (dp[i][amount] != -1)
      return dp[i][amount];

    int notTaken = 0 + coinHelper(coins, amount, dp, i - 1);
    int taken = 1e9;
    if (coins[i] <= amount)
      taken = 1 + coinHelper(coins, amount - coins[i], dp, i);

    return dp[i][amount] = min(notTaken, taken);
  }

public:
  int coinChange(vector<int> &coins, int amount)
  {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    dp[0][amount] = coinHelper(coins, amount, dp, n - 1);

    return dp[0][amount] == 1e9 ? -1 : dp[0][amount];
  }
};

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    int n = coins.size();
    // first value represents the coin denomination while second value
    // denominates the required sum
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

    // initialise the first row with values that would make up the amount
    // with the first coin or coin at zero index
    for (int i = 0; i <= amount; i++)
    {
      if (i % coins[0] != 0)
        dp[0][i] = 1e9;
      else
        dp[0][i] = i / coins[0];
    }

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j <= amount; j++)
      {
        // you dont take the coin to add to the sum
        int notTaken = dp[i - 1][j];
        // we initialise taken to 1e9 to make sure if it doesnt go
        // through the min will be taken as notTaken
        int taken = 1e9;
        // you take the coin to add the sum given it's less than the
        // required sum
        if (coins[i] <= j)
          taken = 1 + dp[i][j - coins[i]];

        // take the maximum value within the two
        dp[i][j] = min(taken, notTaken);
      }
    }

    // return the dp[n - 1] coin based on whether you reached the value or
    // not
    return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
  }
};