#include <vector>

using namespace std;

class Solution {
public:
    void permuteHelper(vector<int>& nums, vector<int>& subset,
                       vector<vector<int>>& ans, int frequency[]) {
        if (subset.size() == nums.size()) {
            ans.push_back(subset);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!frequency[i]) {
                subset.push_back(nums[i]);
                frequency[i] = 1;
                permuteHelper(nums, subset, ans, frequency);
                frequency[i] = 0;
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int freq[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            freq[i] = 0;
        }
        permuteHelper(nums, subset, ans, freq);
        return ans;
    }
};