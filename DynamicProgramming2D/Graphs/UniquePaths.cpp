#include <vector>

using namespace std;

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    int N = m + n - 2;
    int r = m - 1;
    double result = 1;

    for (int i = 1; i <= r; i++)
    {
      result = result * (N - r + i) / i;
    }
    return result;
  }
};

// best intuitive approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        // add padding to handle boundary edge conditions easily and neatly
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // initialise first cell as 1
        dp[1][1] = 1;

        // can start from 1 since 0 is padded and added externally
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // base case
                if (i == 1 && j == 1)
                    continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};


class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
      grid[i][0] = 1;

    for (int i = 0; i < n; i++)
      grid[0][i] = 1;

    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
      }
    }

    return grid[m - 1][n - 1];
  }
};

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = m - 1; i >= 0; i--)
      grid[i][n - 1] = 1;

    for (int i = n - 1; i >= 0; i--)
      grid[m - 1][i] = 1;

    for (int i = m - 2; i >= 0; i--)
    {
      for (int j = n - 2; j >= 0; j--)
      {
        grid[i][j] = grid[i + 1][j] + grid[i][j + 1];
      }
    }

    return grid[0][0];
  }
};