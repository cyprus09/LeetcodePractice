#include <vector>

using namespace std;

class Solution {
public:
    void permuteHelper(vector<int> &subset, vector<int> &nums, vector<vector<int>> &ans, int freq[]){
        if(subset.size() == nums.size()){
            ans.push_back(subset);
            return;
        }
        for(int i = 0;i < nums.size(); i++){
            if(!freq[i]){
                subset.push_back(nums[i]);
                freq[i] = 1;
                permuteHelper(subset, nums, ans, freq);
                freq[i] = 0;
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        int freq[nums.size()];
        for(int i = 0; i < nums.size(); i++) freq[i] = 0;
        permuteHelper(subset, nums, ans, freq);
        return ans;
    }
};