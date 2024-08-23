#include <vector>

using namespace std;

class Solution
{
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
  {
    int n = gas.size();

    int totalGas = 0, totalCost = 0;
    for (int i = 0; i < n; i++)
    {
      totalGas += gas[i];
      totalCost += cost[i];
    }
    if (totalGas - totalCost < 0)
      return -1;

    int totalGasInEnd = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
      totalGasInEnd += gas[i] - cost[i];
      if (totalGasInEnd < 0)
      {
        totalGasInEnd = 0, result = i + 1;
      }
    }
    return result;
  }
};