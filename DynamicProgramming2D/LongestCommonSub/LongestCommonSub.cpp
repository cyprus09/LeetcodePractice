#include <vector>

using namespace std;

// bottom-up approach (can make top-down also by changing index values)
class Solution
{
private:
  int subHelper(string text1, string text2, int ind1, int ind2,
                vector<vector<int>> &dp)
  {
    int size1 = text1.size(), size2 = text2.size();
    if (ind1 == size1 || ind2 == size2)
      return 0;

    if (dp[ind1][ind2] != -1)
      return dp[ind1][ind2];

    if (text1[ind1] == text2[ind2])
      return dp[ind1][ind2] =
                 1 + subHelper(text1, text2, ind1 + 1, ind2 + 1, dp);
    else
      return dp[ind1][ind2] =
                 max(subHelper(text1, text2, ind1 + 1, ind2, dp),
                     subHelper(text1, text2, ind1, ind2 + 1, dp));
  }

public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int size1 = text1.size(), size2 = text2.size();
    vector<vector<int>> dp(size1, vector<int>(size2, -1));
    return subHelper(text1, text2, 0, 0, dp);
  }
};