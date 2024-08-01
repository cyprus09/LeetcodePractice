#include <vector>

using namespace std;

class Solution
{
private:
  vector<int> ans;
  void dfs(int index, vector<int> &dp, vector<int> &nums, int prev)
  {
    if (index == nums.size())
    {
      if (ans.size() < dp.size())
        ans = dp;
      return;
    }
    dfs(index + 1, dp, nums, prev);

    if (prev == -1 || nums[index] % prev == 0)
    {
      dp.push_back(nums[index]);
      dfs(index + 1, dp, nums, nums[index]);
      dp.pop_back();
    }
  }

public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());
    vector<int> dp;
    dfs(0, dp, nums, -1);
    return ans;
  }
};

// explainable solution
class Solution
{
public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> hash(n, 1);

    for (int i = 0; i <= n - 1; i++)
    {
      hash[i] = i;
      for (int prev_index = 0; prev_index <= i - 1; prev_index++)
      {
        if (nums[i] % nums[prev_index] == 0 &&
            1 + dp[prev_index] > dp[i])
        {
          dp[i] = 1 + dp[prev_index];
          hash[i] = prev_index;
        }
      }
    }

    int ans = -1, lastIndex = -1;
    for (int i = 0; i < n; i++)
    {
      if (dp[i] > ans)
      {
        ans = dp[i];
        lastIndex = i;
      }
    }

    vector<int> temp;
    temp.push_back(nums[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    {
      lastIndex = hash[lastIndex];
      temp.push_back(nums[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
  }
};