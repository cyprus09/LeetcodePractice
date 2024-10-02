#include <vector>

using namespace std;

// tabulation approach
class Solution
{
public:
  int climbStairs(int n)
  {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    int prev2 = 1;
    int prev1 = 1;
    int curr = 0;

    for (int i = 2; i <= n; i++)
    {
      curr = prev1 + prev2;
      prev2 = prev1;
      prev1 = curr;
    }

    return curr;
  }
};

// memoisation approach
class Solution
{
private:
  int climbStairsHelper(int n, vector<int> &memo)
  {
    if (n <= 1)
      return 1;
    if (memo[n] != -1)
      return memo[n];
    memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);

    return memo[n];
  }

public:
  int climbStairs(int n)
  {
    vector<int> stairs(n + 1, -1);
    return climbStairsHelper(n, stairs);
  }
};

// tabulation approach
class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 1)
      return 1; // early return to reduce computations

    vector<int> stairs(n + 1, -1);
    stairs[0] = 1; // 0 methods to climb the stairs
    stairs[1] = 1; // 1 method = 1 step
    for (int i = 2; i <= n; i++)
    {
      stairs[i] = stairs[i - 1] + stairs[i - 2];
    }

    return stairs[n];
  }
};