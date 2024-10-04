#include <vector>

using namespace std;

class Solution
{
public:
  int rob(std::vector<int> &nums)
  {
    if (nums.size() == 0)
      return 0;
    int prev1 = 0, prev2 = 0;
    for (int num : nums)
    {
      int temp = prev1;
      prev1 = max(prev2 + num, prev1);
      prev2 = temp;
    }
    return prev1;
  }
};

class Solution
{
public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
      // two options: either to rob the house or not, if yes, 
      // dp[i] will be dp[i] two indices back plus current
      int option1 = dp[i - 1];
      int option2 = dp[i - 2] + nums[i];

      dp[i] = max(option1, option2);
    }

    return dp[n - 1];
  }
};