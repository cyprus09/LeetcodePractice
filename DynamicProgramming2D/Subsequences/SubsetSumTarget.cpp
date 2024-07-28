#include <vector>

using namespace std;

// take or not take approach within a subset to generate subsequences and check if a sub is equal to target (basic imp concept to remember)

// memoisation approach
bool subsetSumHelper(int k, vector<int> &arr, vector<vector<int>> &dp, int i)
{
  if (k == 0)
    return true;
  if (i == 0)
    return arr[0] == k;

  if (dp[i][k] != -1)
    return dp[i][k];

  // not take the value in the array for subset
  bool notTaken = subsetSumHelper(k, arr, dp, i - 1);

  // take the value in the array
  bool taken;
  if (arr[i] <= k)
    taken = subsetSumHelper(k - arr[i], arr, dp, i - 1);

  // if either is successful, you allocate that value to that dp
  return dp[i][k] = taken || notTaken;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // k + 1 is a big value since all values will be lesser than k atleast
  vector<vector<int>> dp(n, vector<int>(k + 1, -1));

  return subsetSumHelper(k, arr, dp, n - 1);
}

// better dp approach
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }

  if (arr[0] <= k)
    dp[0][arr[0]] = true;

  for (int i = 1; i < n; i++)
  {
    for (int target = 1; target <= k; target++)
    {
      bool notTaken = dp[i - 1][target];

      bool taken = false;
      if (arr[i] <= target)
        taken = dp[i - 1][target - arr[i]];

      dp[i][target] = notTaken || taken;
    }
  }

  return dp[n - 1][k];
}