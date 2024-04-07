#include <string>
#include <vector>

using namespace std;

bool isSafe(int node, int color[], vector<vector<int>> &mat, int n, int col){
    for(int k = 0; k < n; k++){
        if(k != node && mat[k][node] == 1 && color[k] == col){
            return false;
        }
    }

    return true;
}

bool solve(int node, int color[], int m, int N, vector<vector<int>> &mat){
    if(node == N) return true;
    for(int i = 1; i <= m; i++){
        if(isSafe(node, color, mat, N, i)){
        color[node] = i;
        if(solve(node + 1, color, m, N, mat)) return true;
        color[node] = 0;
         }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int color[mat.size()];
    for(int i = 0; i < mat.size(); i++){
        color[i] = 0;
    } 
    string ans;
    if(solve(0, color, m, mat.size(), mat)){
        ans = "YES";
    }else{
        ans = "NO";
    }

    return ans;
}