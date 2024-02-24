#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;

        int x = 0;  // missing number
        int y = 0;  // repeated number

        int p = grid.size();
        int q = grid[0].size();

        int n = p * q;
        long long sum = (static_cast<long long>(n) * (n - 1)) / 2;
        long long squareSum = (static_cast<long long>(n) * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0, S2 = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {  
                S += grid[i][j];
                S2 += static_cast<long long>(grid[i][j]) * static_cast<long long>(grid[i][j]);
            }
        }
        long long val1 = S - sum;
        long long val2 = (S2 - squareSum) / val1;

        x = (val1 + val2) / 2;
        y = x - val1;

        ans.push_back(static_cast<int>(-x));
        ans.push_back(static_cast<int>(-y));

        return ans;
    }
};

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0, n = grid.size(), N = n*n;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                sum += grid[i][j];
                sqrSum += grid[i][j] * grid[i][j];
            }
        }
        
        long long c1 = sum - N * (N + 1)/2,  c2 = sqrSum - N*(N+1)*(2*N + 1)/6;
        return {(int)(c2/c1 + c1)/2, (int)(c2/c1 - c1)/2};
    }
};