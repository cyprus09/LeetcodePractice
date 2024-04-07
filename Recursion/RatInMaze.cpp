#include <vector>

using namespace std;

void pathHelper(int i, int j, vector<vector<int>> &mat,
                vector<vector<int>> &visited, int n, vector<string> &ans,
                string move) {
  if (i == n - 1 && j == n - 1) {
    ans.push_back(move);
    return;
  }

  // up
  if (i - 1 >= 0 && mat[i - 1][j] == 1 && !visited[i - 1][j]) {
    visited[i][j] = 1;
    pathHelper(i - 1, j, mat, visited, n, ans, move + 'U');
    visited[i][j] = 0;
  }
  // down
  if (i + 1 < n && mat[i + 1][j] == 1 && !visited[i + 1][j]) {
    visited[i][j] = 1;
    pathHelper(i + 1, j, mat, visited, n, ans, move + 'D');
    visited[i][j] = 0;
  }

  // left
  if (j - 1 >= 0 && mat[i][j - 1] == 1 && !visited[i][j - 1]) {
    visited[i][j] = 1;
    pathHelper(i, j - 1, mat, visited, n, ans, move + 'L');
    visited[i][j] = 0;
  }

  // right
  if (j + 1 < n && mat[i][j + 1] == 1 && !visited[i][j + 1]) {
    visited[i][j] = 1;
    pathHelper(i, j + 1, mat, visited, n, ans, move + 'R');
    visited[i][j] = 0;
  }
}

vector<string> ratMaze(vector<vector<int>> &mat) {
  int n = mat.size();
  vector<string> ans;
  vector<vector<int>> visited(n, vector<int>(n, 0));

  if (mat[0][0] == 1)
    pathHelper(0, 0, mat, visited, n, ans, "");

  return ans;
}