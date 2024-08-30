#include <vector>

using namespace std;

// prim's algo
class Solution
{
public:
  int minCostConnectPoints(vector<vector<int>> &points)
  {
    int n = points.size();
    int edgesUsed = 0;

    vector<bool> inMST(n);
    vector<int> minDist(n, INT_MAX);

    minDist[0] = 0;
    int result = 0;

    while (edgesUsed < n)
    {
      int currMinEdge = INT_MAX, currNode = -1;

      for (int i = 0; i < n; i++)
      {
        if (!inMST[i] && currMinEdge > minDist[i])
        {
          currMinEdge = minDist[i];
          currNode = i;
        }
      }

      result += currMinEdge;
      edgesUsed++;
      inMST[currNode] = true;

      for (int i = 0; i < n; i++)
      {
        int cost = abs(points[currNode][0] - points[i][0]) +
                   abs(points[currNode][1] - points[i][1]);
        if (!inMST[i] && minDist[i] > cost)
          minDist[i] = cost;
      }
    }
    return result;
  }
};