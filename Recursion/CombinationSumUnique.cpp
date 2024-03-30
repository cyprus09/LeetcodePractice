#include <vector>

using namespace std;

class Solution {
public:
    void combinationSum2Helper(vector<int>& candidates,
                               vector<vector<int>>& ans, vector<int>& subset,
                               int index, int target) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            subset.push_back(candidates[i]);
            combinationSum2Helper(candidates, ans, subset, i + 1,
                                  target - candidates[i]);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> subset;
        combinationSum2Helper(candidates, ans, subset, 0, target);
        return ans;
    }
};