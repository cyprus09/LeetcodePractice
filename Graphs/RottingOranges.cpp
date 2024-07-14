#include <vector>
#include <queue>

using namespace std;

class Solution
{
private:
  vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

public:
  int orangesRotting(vector<vector<int>> &grid)
  {
    queue<pair<int, int>> q;
    int m = grid.size(), n = grid[0].size();

    int fresh = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({i, j});
        }
        else if (grid[i][j] == 1)
        {
          fresh++;
        }
      }
    }

    q.push({-1, -1}); // Sentinel to mark the end of the first round of BFS
    int minutes = -1; // Initialize minutes to -1 because the first increment happens before processing

    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      if (row == -1)
      {            // Sentinel encountered
        minutes++; // Increment minutes as we finished one round of BFS
        if (!q.empty())
        {
          q.push({-1, -1}); // Add sentinel for the next round if there are more cells to process
        }
      }
      else
      {
        for (int i = 0; i < 4; i++)
        {
          int x = row + direction[i][0];
          int y = col + direction[i][1];

          if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
          {
            continue; // Skip out-of-bounds or non-fresh oranges
          }

          grid[x][y] = 2; // Rot the fresh orange
          fresh--;        // Decrease fresh orange count
          q.push({x, y}); // Add newly rotten orange to the queue
        }
      }
    }

    if (fresh == 0)
    {
      return minutes; // All fresh oranges are rotted
    }
    return -1; // Some fresh oranges could not be rotted
  }
};