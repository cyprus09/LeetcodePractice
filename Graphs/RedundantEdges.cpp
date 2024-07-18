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

  int unionFind(vector<int> &parents, vector<int> &ranks, int n1, int n2)
  {
    int p1 = find(parents, parents[n1]);
    int p2 = find(parents, parents[n2]);

    if (p1 == p2)
      return false;

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
    return true;
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();
    vector<int> parents;
    vector<int> ranks(n + 1, 1);

    for (int i = 0; i < n + 1; i++)
    {
      parents.push_back(i);
    }

    for (const auto &edge : edges)
    {
      int n1 = edge[0];
      int n2 = edge[1];
      if (!unionFind(parents, ranks, n1, n2))
      {
        return edge;
      }
    }

    return {};
  }
};