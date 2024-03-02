#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//brute force approach
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    for(int m = k + 1; m < nums.size(); m++){
                        long long sum = nums[i] + nums[j] + nums[k] + nums[m];
                        if(sum == target){
                            vector<int>temp = {nums[i], nums[j], nums[k], nums[m]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//optimal approach
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                set<long long> hashset;
                for(int k = j + 1; k < n; k++){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k];
                    long long remainderNum = target - sum;
                    if (hashset.find(remainderNum) != hashset.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(remainderNum)};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//even better approach
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int k = j + 1;
                int l = nums.size() - 1;
                while(k < l){
                long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if(sum < target){
                        k++;
                        continue;
                    }
                    if(sum > target){
                        l--;
                        continue;
                    }
                    if(sum == target){
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k - 1]){
                            k++;
                        }
                        while(l > k && nums[l] == nums[l + 1]){
                            l--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};