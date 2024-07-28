#include <vector>
#include <algorithm>

using namespace std;

// memoisation approach (top-down approach)
class Solution
{
private:
  long profitHelper(int n, int index, int buy, vector<vector<long>> &dp,
                    vector<int> prices)
  {
    if (index == n)
      return 0;

    if (dp[index][buy] != -1)
      return dp[index][buy];

    long maxProfit = 0;

    // can buy
    if (buy == 0)
      maxProfit =
          max(0 + profitHelper(n, index + 1, 0, dp, prices),
              -prices[index] + profitHelper(n, index + 1, 1, dp, prices));

    // can sell
    if (buy == 1)
      maxProfit =
          max(0 + profitHelper(n, index + 1, 1, dp, prices),
              prices[index] + profitHelper(n, index + 1, 0, dp, prices));

    return dp[index][buy] = maxProfit;
  }

public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<long>> dp(n, vector<long>(2, -1));

    long res = profitHelper(n, 0, 0, dp, prices);
    return (int)res;
  }
};

// tabulation approach (bottom-up approach)
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    // bool array with all set to zero(false)
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    int profit = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int buy = 0; buy <= 1; buy++)
      {
        if (buy == 0)
          profit = max(0 + dp[i + 1][0], -prices[i] + dp[i + 1][1]);
        if (buy == 1)
          profit = max(0 + dp[i + 1][1], prices[i] + dp[i + 1][0]);
        dp[i][buy] = profit;
      }
    }
    return dp[0][0];
  }
};

// space optimisation approach (same as dp)
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();

    vector<int> ahead(2, 0);
    vector<int> curr(2, 0);
    ahead[0] = ahead[1] = 0;

    int profit = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      for (int buy = 0; buy < 2; buy++)
      {
        // can buy
        if (buy == 0)
          profit = max(0 + ahead[0], -prices[i] + ahead[1]);
        // can sell
        if (buy == 1)
          profit = max(0 + ahead[1], prices[i] + ahead[0]);

        curr[buy] = profit;
      }
      ahead = curr;
    }

    return curr[0];
  }
};