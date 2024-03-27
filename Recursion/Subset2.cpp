#include <iostream>
#include <vector>
#include <algorithm>

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