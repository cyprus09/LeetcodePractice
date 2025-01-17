#include <vector>

using namespace std;

class Solution
{
  int find(int i, vector<int> &parents)
  {
    // we end up looking for it if the parent isnt the index value
    // optimise the find algo by moving the representative right under
    // (path compression)
    if (parents[i] != i)
      parents[i] = find(parents[i], parents);

    return parents[i];
  }

  void unionSet(int x, int y, vector<int> &parents, vector<int> &rank)
  {
    int rootX = find(x, parents);
    int rootY = find(y, parents);
    // we maintain a rank array to keep track of which one is actually the
    // parent and then update the parent value accordingly
    if (rootX != rootY)
    {
      if (rank[rootX] > rank[rootY])
        parents[rootY] = rootX;
      else if (rank[rootX] < rank[rootY])
        parents[rootX] = rootY;
      else
      {
        parents[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    // isConnected is basically the adjacency matrix which shows which nodes
    // are connected with which
    // if i and j are directly connected, isConnected ? 1 : 0
    // have to return the total number of provinces, basically return how
    // many connected components
    // we will use the union find algorithm to solve this question
    // fill the initial parent array with the name of the cities, since each
    // node is it's own parent
    int n = isConnected.size();
    vector<int> parents(n);
    for (int i = 0; i < n; i++)
    {
      parents[i] = i;
    }

    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (isConnected[i][j] == 1)
          unionSet(i, j, parents, rank);
      }
    }

    // now just run through the parent array and check if the i-th index ==
    // i, if yes, it's a separate province
    int numProvinces = 0;
    for (int i = 0; i < n; i++)
    {
      if (parents[i] == i)
        numProvinces++;
    }

    return numProvinces;
  }
};