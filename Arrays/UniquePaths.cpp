#include <vector>

using namespace std;

//recursive approach
class Solution {
public:
    int uniquePathsHelper(int i, int j, int m, int n){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        return uniquePathsHelper(i + 1, j, m, n) + uniquePathsHelper(i, j + 1, m, n);
    }
    int uniquePaths(int m, int n) {
        return uniquePathsHelper(0, 0, m, n);
    }
};

//dp approach
class Solution {
public:
    int uniquePathsHelper(int i, int j, int m, int n, vector<vector<int>> &dp){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i >= m || j >= n){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = uniquePathsHelper(i + 1, j, m, n, dp) + uniquePathsHelper(i, j + 1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return uniquePathsHelper(0, 0, m, n, dp);
    }
};

//math approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = m - 1;
        double result = 1;

        for(int i = 1; i <= r; i++){
            result = result * (N - r + i) / i;
        }
        return result;
    }
};