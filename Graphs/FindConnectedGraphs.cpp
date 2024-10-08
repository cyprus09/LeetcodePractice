#include <vector>

using namespace std;

class Solution
{
private:
  int find(vector<int> &parents, int n)
  {
    int p = parents[n];
    while (p != parents[p])
    {
      parents[p] = parents[parents[p]];
      p = parents[p];
    }
    return p;
  }

  int doUnion(vector<int> &parents, vector<int> &ranks, int n1, int n2)
  {
    int p1 = find(parents, n1);
    int p2 = find(parents, n2);
    if (p1 == p2)
      return 0;

    if (ranks[p1] > ranks[p2])
    {
      parents[p2] = p1;
      ranks[p1] += ranks[p2];
    }
    else
    {
      parents[p1] = p2;
      ranks[p2] += ranks[p1];
    }
    return 1;
  }

public:
  int countComponents(int n, vector<vector<int>> &edges)
  {
    vector<int> parents;
    vector<int> ranks(n, 1);

    for (int i = 0; i < n; i++)
      parents.push_back(i);

    int result = n;
    for (int i = 0; i < edges.size(); i++)
    {
      int n1 = edges[i][0];
      int n2 = edges[i][1];

      result -= doUnion(parents, ranks, n1, n2);
    }
    return result;
  }
};
