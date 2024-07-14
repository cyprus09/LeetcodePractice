#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
  vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

public:
  void islandsAndTreasure(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
          q.push({i, j});
      }
    }

    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++)
      {
        int x = row + direction[i][0];
        int y = col + direction[i][1];

        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 2147483647)
        {
          continue;
        }

        grid[x][y] = grid[row][col] + 1;
        q.push({x, y});
      }
    }
  }
};
