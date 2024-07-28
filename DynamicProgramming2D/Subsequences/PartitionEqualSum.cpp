#include <vector>
#include <unordered_set>

using namespace std;

// memoisation approach (bottom-up)
// based on take and not take concept
class Solution
{
private:
  bool partitionHelper(vector<int> &nums, vector<vector<int>> &dp, int i,
                       int target)
  {
    if (target == 0)
      return true;
    if (i <= 0)
      return nums[0] == target;

    if (dp[i][target] != -1)
      return dp[i][target];

    bool notTaken = partitionHelper(nums, dp, i - 1, target);
    bool taken = false;
    if (nums[i] <= target)
      taken = partitionHelper(nums, dp, i - 1, target - nums[i]);

    return dp[i][target] = taken || notTaken;
  }

public:
  bool canPartition(vector<int> &nums)
  {
    int n = nums.size();

    int sum = 0;
    for (int num : nums)
      sum += num;

    if (sum % 2 != 0)
      return false;

    sum /= 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    int ans = partitionHelper(nums, dp, n - 1, sum);

    return ans;
  }
};

// dp approach (top-down approach)
class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int n = nums.size();

    int sum = 0;
    for (int num : nums)
      sum += num;

    if (sum % 2 != 0)
      return false;

    sum /= 2;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
      dp[i][0] = true;

    if (nums[0] <= sum)
      dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
      for (int target = 1; target <= sum; target++)
      {
        bool notTaken = dp[i - 1][target];
        bool taken = false;
        if (nums[i] <= target)
          taken = dp[i - 1][target - nums[i]];
        dp[i][target] = taken || notTaken;
      }
    }

    return dp[n - 1][sum];
  }
};

class Solution
{
public:
  bool canPartition(vector<int> &nums)
  {
    int sum = 0;
    for (int num : nums)
      sum += num;

    if (sum % 2 != 0)
      return false;

    int sumToEqual = sum / 2;

    vector<bool> dp(sumToEqual + 1, false);
    dp[0] = true;

    for (int num : nums)
    {
      for (int i = sumToEqual; i >= num; i--)
      {
        dp[i] = dp[i] || dp[i - num];
      }
    }

    return dp[sumToEqual];
  }
};