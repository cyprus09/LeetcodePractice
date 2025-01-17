#include <vector>

using namespace std;

class Solution
{
  int m, n;
  void dfs(vector<vector<int>> &image, int i, int j, int startColor,
           int newColor)
  {
    if (i < 0 || j < 0 || i >= m || j >= n || image[i][j] != startColor)
      return;

    image[i][j] = newColor;

    dfs(image, i - 1, j, startColor, newColor);
    dfs(image, i + 1, j, startColor, newColor);
    dfs(image, i, j - 1, startColor, newColor);
    dfs(image, i, j + 1, startColor, newColor);
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color)
  {
    m = image.size(), n = image[0].size();
    int startColor = image[sr][sc];

    if (startColor == color)
      return image;

    // no need to run a loop, it will automatically spread around
    dfs(image, sr, sc, startColor, color);

    return image;
  }
};