#include <vector>

using namespace std;

class Solution
{
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k)
  {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    // base case
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
      // initialise the max value to keep track with the var
      int maxPart = 0;
      for (int j = 1; j <= min(i, k); j++)
      {
        // is the maxValue of prefix
        maxPart = max(maxPart, arr[i - j]);
        // calculate prefix and current max sum
        int option = dp[i - j] + maxPart * j;
        // update dp state accordingly
        dp[i] = max(dp[i], option);
      }
    }

    return dp[n];
  }
};