#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                temp.push_back(matrix[i][j]);
            }
        }
        int low = 0;
        int high = temp.size();

        while(low <= temp.size() && high > 0){
            int mid = (low + high - 1) / 2;

            if(temp[mid] < target){
                low = mid + 1;
            }
            if(temp[mid] > target){
                high = mid - 1;
            }
            if(temp[mid] == target){
                return true;
            }
        }

        return false;
    }
};

//without using extra space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;

            if (matrix[row][col] == target){
                return true;
            } 
            else if (matrix[row][col] < target){
                low = mid + 1;
            } 
            else{ 
                high = mid - 1;
            }
        }
        return false;
    }
};