#include <vector>

using namespace std;

// dp approach
class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    int first = 1;
    int second = 2;
    int result = 0;

    for (int i = 2; i < n; i++)
    {
      result = first + second;
      first = second;
      second = result;
    }

    return result;
  }
};

// memoisation approach
class Solution
{
private:
  int climbStairsHelper(vector<int> &memo, int n)
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    if (memo[n] != -1)
      return memo[n];

    memo[n] =
        climbStairsHelper(memo, n - 1) + climbStairsHelper(memo, n - 2);
    return memo[n];
  }

public:
  int climbStairs(int n)
  {
    vector<int> memo(n + 1, -1);
    return climbStairsHelper(memo, n);
  }
};