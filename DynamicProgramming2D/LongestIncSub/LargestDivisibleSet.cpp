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