#include <vector>

using namespace std;

class Solution {
private:
    void setColumnsZero(vector<vector<int>> &matrix, int col){
        for(int i = 0; i < matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }

    void setRowsZero(vector<vector<int>> &matrix, int row){
        for(int i = 0; i < matrix[0].size(); i++){
            matrix[row][i] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;

        int n = matrix[0].size();

        vector<pair<int, int>> zeroes;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    zeroes.push_back({i, j});
                }
            }
        }

        for(const auto& zero : zeroes){
            setColumnsZero(matrix, zero.second);
            setRowsZero(matrix, zero.first);
        }
    }
};