#include <vector>

using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // initialise to check if one string is empty
    for (int i = 1; i <= m; i++)
    {
      dp[i][0] = i;
    }

    for (int j = 1; j <= n; j++)
    {
      dp[0][j] = j;
    }
    // dp[i][j] tracks the length again
    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (word1[i - 1] == word2[j - 1])
          // dont do anything just take from previous
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] =
              min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                //   replace            delete         insert
      }
    }

    return dp[m][n];
  }
};