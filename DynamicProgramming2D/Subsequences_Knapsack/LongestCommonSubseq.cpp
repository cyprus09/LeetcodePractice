#include <vector>

using namespace std;

// bottom-up approach
class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int m = text1.size(), n = text2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        if (text1[i] == text2[j])
          dp[i][j] = 1 + dp[i + 1][j + 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
    return dp[0][0];
  }
};

// top down approach
class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int size1 = text1.size(), size2 = text2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    for (int i = 1; i < size1 + 1; i++)
    {
      for (int j = 1; j < size2 + 1; j++)
      {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
    return dp[size1][size2];
  }
};