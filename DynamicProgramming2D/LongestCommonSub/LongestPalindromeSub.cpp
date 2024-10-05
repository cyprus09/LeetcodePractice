#include <vector>

using namespace std;

class Solution
{
  // take dp array limits one place bigger than constraints
  int dp[1000][1000];
  string str;

  int solve(int l, int r)
  {
    // l is just after r, denotes empty string
    // we take l == r + 1 since both are inclusive
    if (l == r + 1)
      return 0;
    // exactly the same substr
    if (l == r)
      return 1;

    if (dp[l][r] > 0)
      return dp[l][r];

    if (str[l] == str[r])
      // take both ends and add 2 to the length to cache it in the dp
      // array
      dp[l][r] = solve(l + 1, r - 1) + 2;
    else
      // exclude from left or right and take it's max
      dp[l][r] = max(solve(l + 1, r), solve(l, r - 1));

    return dp[l][r];
  }

public:
  int longestPalindromeSubseq(string s)
  {
    str = s;
    return solve(0, s.size() - 1);
  }
};