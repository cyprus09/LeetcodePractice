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