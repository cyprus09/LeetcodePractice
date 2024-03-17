#include <set>
#include <iostream>
#include <vector>

using namespace std;

//uses extra space
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++){
            set<int> st;
            for(int j = i + 1; j < nums.size(); j++){
                int target = -(nums[i] + nums[j]);
                if(st.find(target) != st.end()){
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                st.insert(nums[j]);
            }
        }

    vector<vector<int>> finalAns(ans.begin(), ans.end());
    return finalAns;
    }
};

//best approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++){
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                if(sum > 0){
                    k--;
                }
                if(sum == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};
