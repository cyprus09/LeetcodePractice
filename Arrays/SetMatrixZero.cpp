#include <vector>

using namespace std;

class Solution {
public:
    void setColumnZeroes(vector<vector<int>>& matrix, int col){
        for(int i = 0; i < matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }

    void setRowZeroes(vector<vector<int>>& matrix, int row){
        for(int i = 0; i < matrix[0].size(); i++){
            matrix[row][i] = 0;
        }
    }

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

        //const auto& makes sure we change matrix values and not its copies
        for(const auto& it : zeroes){
            setRowZeroes(matrix, it.first);
            setColumnZeroes(matrix, it.second);
        }
    }
};