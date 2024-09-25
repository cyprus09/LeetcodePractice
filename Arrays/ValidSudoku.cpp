#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        const int cnt = 9;
        bool row[cnt][cnt] = {false};
        bool col[cnt][cnt] = {false};
        bool sub[cnt][cnt] = {false};

        for (int r = 0; r < cnt; ++r)
        {
            for (int c = 0; c < cnt; ++c)
            {
                if (board[r][c] == '.')
                    continue;

                int idx = board[r][c] - '0' - 1;
                int area = (r / 3) * 3 + (c / 3);

                if (row[r][idx] || col[c][idx] || sub[area][idx])
                {
                    return false;
                }

                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> a;
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c == '.')
                    continue;
                if (a.count(c) == 0)
                    a.insert(c);
                else
                    return false;
            }
        }
        for (int i = 0; i < 9; i++)
        {
            unordered_set<char> a;
            for (int j = 0; j < 9; j++)
            {
                char c = board[j][i];
                if (c == '.')
                    continue;
                if (a.count(c) == 0)
                    a.insert(c);
                else
                    return false;
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                unordered_set<char> a;
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        char c = board[k + 3 * i][l + 3 * i];
                        if (c == '.')
                            continue;
                        if (a.count(c) == 0)
                            a.insert(c);
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

// another valid approach
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> square;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char num = board[i][j];

                if (num == '.')
                    continue;

                if (rows[i].count(num))
                    return false;
                if (cols[j].count(num))
                    return false;

                int index = (i / 3) * 3 + (j / 3);
                if (square[index].count(num))
                    return false;

                rows[i].insert(num);
                cols[j].insert(num);
                square[index].insert(num);
            }
        }

        return true;
    }
};