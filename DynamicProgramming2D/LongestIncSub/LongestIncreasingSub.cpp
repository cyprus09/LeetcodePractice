#include <vector>

using namespace std;

class Solution
{
private:
  int subsequenceHelper(vector<int> &nums, int index, int prev, vector<vector<int>> &dp)
  {
    if (index == nums.size())
      return 0;

    if (dp[index][prev + 1] != -1)
      return dp[index][prev + 1];

    int notTaken = subsequenceHelper(nums, index + 1, prev, dp);

    int taken = 0;
    if (prev == -1 || nums[prev] < nums[index])
      taken = 1 + subsequenceHelper(nums, index + 1, index, dp);

    return dp[index][prev + 1] = max(taken, notTaken);
  }

public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return subsequenceHelper(nums, 0, -1, dp);
  }
};

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {
      for (int prev_index = index - 1; prev_index >= -1; prev_index--)
      {
        int notTaken = 0 + dp[index + 1][prev_index + 1];
        int taken = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index])
          taken = 1 + dp[index + 1][index + 1];

        dp[index][prev_index + 1] = max(taken, notTaken);
      }
    }

    return dp[0][0];
  }
};

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;

    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], 1 + dp[j]);
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};

class Solution
{
public:
  int longestCommonSubsequence(string text1, string text2)
  {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    // base cases to make code faster for certain test cases
    if (text1 == text2)
      return text1.size();
    if (m == 0 || n == 0)
      return 0;

    for (int i = 1; i <= m; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        // 3 options : dont take from second, dont from first and take
        // from both dp[i][j] will essentially store the length of
        // prefixes that have max subsequence
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
      }
    }

    return dp[m][n];
  }
};