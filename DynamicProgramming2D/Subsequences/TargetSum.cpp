#include <vector>

using namespace std;

/* make two equations
1) S1 + S2 = target and 2) S1 = totSum - S2
solving will give S2 = (totSum - target) / 2
edge case: 1) totSum < target
2) totSum - target = odd (S2 cant be fraction)
return 0 */

// memoisation approach
class Solution
{
private:
  int targetSumHelper(vector<int> &nums, vector<vector<int>> &dp, int target,
                      int index)
  {
    if (index == 0)
    {
      if (target == 0 && nums[0] == 0)
        return 2; // two ways : include or exclude
      if (target == 0 || target == nums[0])
        return 1; // one way : include or exclude
      return 0;   // no way to partition
    }

    if (dp[index][target] != -1)
      return dp[index][target];

    int notTaken = targetSumHelper(nums, dp, target, index - 1);

    int taken = 0;
    if (nums[index] <= target)
      taken = targetSumHelper(nums, dp, target - nums[index], index - 1);

    return dp[index][target] = (notTaken + taken);
  }

public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int n = nums.size();
    int total = 0;

    for (int num : nums)
      total += num;

    if ((total - target) < 0)
      return 0;

    if ((total - target) % 2 == 1)
      return 0;

    int s2 = (total - target) / 2;

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return targetSumHelper(nums, dp, s2, n - 1);
  }
};

// better
class Solution
{
private:
  const int mod = (int)1e9 + 7;

public:
  int findTargetSumWays(vector<int> &nums, int target)
  {
    int total = 0;
    for (int num : nums)
      total += num;

    if ((total < target) || ((total - target) % 2 == 1))
      return 0;

    int s2 = (total - target) / 2;

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(s2 + 1, 0));

    dp[0][0] = (nums[0] == 0) ? 2 : 1;

    if (nums[0] != 0 && nums[0] <= s2)
      dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j <= s2; j++)
      {
        int notTaken = dp[i - 1][j];

        int taken = 0;
        if (nums[i] <= j)
          taken = dp[i - 1][j - nums[i]];

        dp[i][j] = (notTaken + taken) % mod;
      }
    }
    return dp[n - 1][s2];
  }
};