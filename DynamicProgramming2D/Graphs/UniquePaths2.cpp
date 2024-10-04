#include <vector>

using namespace std;

class Solution
{
private:
  int pathHelper(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
  {
    if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
      return 0;
    if (i == 0 && j == 0)
      return 1;
    if (i < 0 || j < 0)
      return 0;
    if (dp[i][j] != -1)
      return dp[i][j];

    int down = pathHelper(i - 1, j, obstacleGrid, dp);
    int right = pathHelper(i, j - 1, obstacleGrid, dp);

    return dp[i][j] = down + right;
  }

public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    int res = pathHelper(m - 1, n - 1, obstacleGrid, dp);
    return res;
  }
};

// better intuitive approach
class Solution
{
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    // early return
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
      return 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // there would never be an obstacle where the person is starting we can
    // assume it's obvious
    dp[1][1] = 1;

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i == 1 && j == 1)
          continue;
        // take i - 1 and j - 1 since you are taking a 1-indexed array
        // for the dp
        if (obstacleGrid[i - 1][j - 1] == 1)
          dp[i][j] = 0;
        else
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m][n];
  }
};