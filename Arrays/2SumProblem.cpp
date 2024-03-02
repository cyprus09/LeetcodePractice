#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//using hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++){
            int moreNeeded = target - nums[i];
            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded], i};
            }
            mpp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

//using sorting
class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> originalIndices(nums.size());  
        for (int i = 0; i < nums.size(); ++i) {
            originalIndices[i] = i;
        }

        //sort the original indices
        sort(originalIndices.begin(), originalIndices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[originalIndices[left]] + nums[originalIndices[right]];
            if (sum == target) {
                ans.push_back(originalIndices[left]);
                ans.push_back(originalIndices[right]);
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return ans;
    }
};
