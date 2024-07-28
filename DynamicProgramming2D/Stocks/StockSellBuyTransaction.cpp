#include <vector>

using namespace std;

// memoisation approach
class Solution
{
private:
  int profitHelper(vector<int> prices, int i, int buy, int n, int fee, vector<vector<int>> &dp)
  {
    if (i == n)
      return 0;

    if (dp[i][buy] != -1)
      return dp[i][buy];

    int profit;

    if (buy == 0)
    {
      profit = max(0 + profitHelper(prices, i + 1, 0, n, fee, dp),
                   -prices[i] + profitHelper(prices, i + 1, 1, n, fee, dp));
    }

    /* we subtract (-) fee here if we decide to sell only
    since fee is for a complete transaction
    only charged once for each stock purchase and sell */

    if (buy == 1)
    {
      profit = max(0 + profitHelper(prices, i + 1, 1, n, fee, dp),
                   prices[i] - fee + profitHelper(prices, i + 1, 0, n, fee, dp));
    }

    return dp[i][buy] = profit;
  }

public:
  int maxProfit(vector<int> &prices, int fee)
  {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    if (n == 0)
      return 0;

    int ans = profitHelper(prices, 0, 0, n, fee, dp);
    return ans;
  }
};

// optimal approach
class Solution
{
public:
  int maxProfit(vector<int> &prices, int fee)
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
          profit = max(0 + ahead[1], prices[i] + ahead[0] - fee);

        curr[buy] = profit;
      }
      ahead = curr;
    }

    return curr[0];
  }
};
