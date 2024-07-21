#include <vector>

using namespace std;

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                        int k)
  {
    vector<int> prices(n, INT_MAX);
    prices[src] = 0;

    for (int i = 0; i < k + 1; i++)
    {
      vector<int> tempPrices(prices.begin(), prices.end());

      for (auto it : flights)
      {
        int s = it[0];
        int d = it[1];
        int p = it[2];

        if (prices[s] == INT_MAX)
          continue;
        if (prices[s] + p < tempPrices[d])
          tempPrices[d] = prices[s] + p;
      }
      prices = tempPrices;
    }
    return prices[dst] == INT_MAX ? -1 : prices[dst];
  }
};