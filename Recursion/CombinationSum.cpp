#include <vector>

using namespace std;

class Solution {
public:
    void combinationSumHelper(vector<int> &candidates, vector<int> &subset, vector<vector<int>> &ans, int index, int target){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(subset);
                //can just return after target == 0 will decrease runtime
            }
            return;
        }

        if(candidates[index] <= target){
            subset.push_back(candidates[index]);
            combinationSumHelper(candidates, subset, ans, index, target - candidates[index]);
            subset.pop_back();
        }

        combinationSumHelper(candidates, subset, ans, index + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        combinationSumHelper(candidates, subset, ans, 0, target);
        return ans;
    }
};