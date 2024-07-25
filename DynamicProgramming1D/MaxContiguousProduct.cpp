#include <vector>
#include <algorithm>

using namespace std;

// non-dp approach (kadane's algo)
int maxProduct(vector<int> &nums)
{
  int maxi = INT_MIN;
  int prod = 1;

  for (int i = 0; i < nums.size(); i++)
  {
    prod *= nums[i];
    maxi = max(prod, maxi);
    if (prod == 0)
      prod = 1;
  }
  prod = 1;
  for (int i = nums.size() - 1; i >= 0; i--)
  {
    prod *= nums[i];

    maxi = max(prod, maxi);
    if (prod == 0)
      prod = 1;
  }
  return maxi;
}

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
      long long n = nums[i];

      long long tempMax = currMax * n;
      long long tempMin = currMin * n;
      currMax = max(max(tempMax, tempMin), n);
      currMin = min(min(tempMax, tempMin), n);
      result = max(result, currMax);
    }

    return (int)result;
  }
};