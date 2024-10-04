#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    // initialise with padding to a really high number
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1000000));
    dp[1][1] = grid[0][0];

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        // base case already initialised earlier
        if (i == 1 && j == 1)
          continue;
        // either you take up or left with current
        int option1 = grid[i - 1][j - 1] + dp[i - 1][j];
        int option2 = grid[i - 1][j - 1] + dp[i][j - 1];

        // the current dp cell will be the min of those two
        dp[i][j] = min(option1, option2);
      }
    }

    return dp[m][n];
  }
};