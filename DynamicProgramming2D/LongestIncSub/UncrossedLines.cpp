#include <vector>

using namespace std;

// exactly same as longest common subsequence
class Solution
{
public:
  int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    if (nums1 == nums2)
      return m;
    if (m == 0 || n == 0)
      return 0;

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (nums1[i - 1] == nums2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
    }

    return dp[m][n];
  }
};