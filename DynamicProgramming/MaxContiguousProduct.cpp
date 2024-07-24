#include <vector>
#include <algorithm>

using namespace std;

// non-dp approach
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    double maxProduct = nums[0], minProduct = nums[0], result = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      double num = nums[i];

      double tempMax = max(num, max(maxProduct * num, minProduct * num));
      double tempMin = min(num, min(maxProduct * num, minProduct * num));

      maxProduct = tempMax;
      minProduct = tempMin;

      result = max(result, maxProduct);
    }

    return result;
  }
};

// dp approach
class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    long long result = nums[0];
    long long currMin = 1, currMax = 1;

    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];

      long long temp = currMax * n;
      currMax = max(max(n * currMax, n * currMin), n);
      currMin = min(min(temp, n * currMin), n);
      result = max(result, currMax);
    }

    return result;
  }
};