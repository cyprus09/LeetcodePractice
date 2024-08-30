#include <vector>

using namespace std;

class Solution
{
private:
  void dfs(vector<vector<int>> &result, vector<int> &nums, vector<int> &curr, int i)
  {
    if (i == nums.size())
    {
      result.push_back(curr);
      return;
    }

    curr.push_back(nums[i]);
    dfs(result, nums, curr, i + 1);

    curr.pop_back();
    dfs(result, nums, curr, i + 1);
  }

public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    vector<vector<int>> result;
    vector<int> curr;
    dfs(result, nums, curr, 0);
    return result;
  }
};