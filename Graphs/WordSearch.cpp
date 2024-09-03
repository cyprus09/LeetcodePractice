#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
  int m, n;
  bool dfs(vector<vector<char>> &board, string word, int i, int j,
           int index)
  {
    if (index == word.size())
      return true;
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
      return false;

    char temp = board[i][j];
    board[i][j] = '0';

    bool found = dfs(board, word, i + 1, j, index + 1) ||
                 dfs(board, word, i - 1, j, index + 1) ||
                 dfs(board, word, i, j + 1, index + 1) ||
                 dfs(board, word, i, j - 1, index + 1);

    board[i][j] = temp;
    return found;
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word[0] && dfs(board, word, i, j, 0))
          return true;
      }
    }
    return false;
  }
};

// another approach
class Solution
{
private:
  int m, n;
  bool dfs(vector<vector<char>> &board, string word, int i, int j, int index,
           vector<vector<bool>> &visited)
  {
    if (index == word.size())
      return true;
    if (i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[index] ||
        visited[i][j])
      return false;

    visited[i][j] = true;

    bool found = dfs(board, word, i + 1, j, index + 1, visited) ||
                 dfs(board, word, i - 1, j, index + 1, visited) ||
                 dfs(board, word, i, j + 1, index + 1, visited) ||
                 dfs(board, word, i, j - 1, index + 1, visited);

    visited[i][j] = false;
    return found;
  }

public:
  bool exist(vector<vector<char>> &board, string word)
  {
    m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (board[i][j] == word[0] &&
            dfs(board, word, i, j, 0, visited))
          return true;
      }
    }
    return false;
  }
};