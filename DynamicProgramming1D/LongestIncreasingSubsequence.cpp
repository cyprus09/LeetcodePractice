#include <vector>
#include <algorithm>

using namespace std;

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