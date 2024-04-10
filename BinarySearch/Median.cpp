#include <vector>

using namespace std;

//brute force approach
int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> sortedOrder;
    int count = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            sortedOrder.push_back(matrix[i][j]);
            count++;
        }
    }

    sort(sortedOrder.begin(), sortedOrder.end());
    int ans = sortedOrder[count/2];

    return ans;
}

//optimal approach : binary search
