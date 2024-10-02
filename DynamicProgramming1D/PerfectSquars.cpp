#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
  int numSquares(int n)
  {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int j = 1; j <= n; j++)
    {
      int mini = INT_MAX;
      for (int i = 1; i <= sqrt(j); i++)
      {
        int square = i * i;
        int curr = 1 + dp[j - square];
        mini = min(mini, curr);
      }
      dp[j] = mini;
    }
    return dp[n];
  }
};