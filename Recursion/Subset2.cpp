#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i = 0; i < (1 << n); i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1) temp.push_back(nums[j]);
            }

            sort(temp.begin(), temp.end());
            if(count(ans.begin(), ans.end(), temp) == 0) ans.push_back(temp);
        }

        return ans;
    }
};

//optimal approach
class Solution {
public:
    void subsetHelper(vector<int> &nums, vector<int> subset, set<vector<int>> &res, int index){
        if(index == nums.size()){
            sort(subset.begin(), subset.end());
            res.insert(subset);
            return;
        }

        subset.push_back(nums[index]);
        subsetHelper(nums, subset, res, index + 1);
        subset.pop_back();
        subsetHelper(nums, subset, res, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> subset;
        subsetHelper(nums, subset, res, 0);
        for(auto it = res.begin(); it != res.end(); it++){
            ans.push_back(*it);
        }

        return ans;
    }
};