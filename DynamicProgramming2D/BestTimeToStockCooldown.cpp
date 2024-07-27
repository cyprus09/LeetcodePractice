#include <vector>
#include <algorithm>

using namespace std;

/* exactly same as sell buy stock 2, we have to two options:
buy or sell (0 and 1),
with each has whether to buy now or next day,
just that if we decide to sell,
we do i + 2 in one case */

// memoisation approach
class Solution
{
private:
  int profitHelper(int i, int buy, int n, vector<vector<int>> &dp,
                   vector<int> prices)
  {
    // i >= n cause for i + 2 if it goes out of bounds
    if (i >= n)
      return 0;
    if (dp[i][buy] != -1)
      return dp[i][buy];

    int profit = 0;
    if (buy == 0)
      profit = max(0 + profitHelper(i + 1, 0, n, dp, prices),
                   -prices[i] + profitHelper(i + 1, 1, n, dp, prices));
    if (buy == 1)
      profit = max(0 + profitHelper(i + 1, 1, n, dp, prices),
                   prices[i] + profitHelper(i + 2, 0, n, dp, prices));
    return dp[i][buy] = profit;
  }

public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    int ans = profitHelper(0, 0, n, dp, prices);
    return ans;
  }
};

// dp approach
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    // bool array with all set to zero(false)
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    int profit = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int buy = 0; buy <= 1; buy++)
      {
        if (buy == 0)
          profit = max(0 + dp[i + 1][0], -prices[i] + dp[i + 1][1]);
        if (buy == 1)
        {
          profit = max(0 + dp[i + 1][1], prices[i] + dp[i + 2][0]);
        }
        dp[i][buy] = profit;
      }
    }
    return dp[0][0];
  }
};

// space optimisation
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> front1(2, 0);
    vector<int> front2(2, 0);

    int profit = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      for (int buy = 0; buy <= 1; buy++)
      {
        if (buy == 0)
          profit = max(0 + front1[0], -prices[i] + front1[1]);
        if (buy == 1)
        {
          profit = max(0 + front1[1], prices[i] + front2[0]);
        }
        curr[buy] = profit;
      }
      front2 = front1;
      front1 = curr;
    }
    return curr[0];
  }
};

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int sold = 0, hold = INT_MIN, rest = 0;

    for (int i = 0; i < prices.size(); ++i)
    {
      int prevSold = sold;
      sold = hold + prices[i];
      hold = max(hold, rest - prices[i]);
      rest = max(rest, prevSold);
    }

    return max(sold, rest);
  }
};