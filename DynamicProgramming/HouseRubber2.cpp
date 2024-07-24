#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
  int robHelper(vector<int> &nums, int start, int end)
  {
    int prev = 0;
    int curr = 0;
    int next = 0;

    for (int i = start; i <= end; i++)
    {
      next = max(prev + nums[i], curr);
      prev = curr;
      curr = next;
    }
    return curr;
  }

public:
  int rob(vector<int> &nums)
  {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    int range1 = robHelper(nums, 0, n - 2);
    int range2 = robHelper(nums, 1, n - 1);

    return max(range1, range2);
  }
};