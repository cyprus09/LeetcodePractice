#include <iostream>
#include <vector>
#include <set>

using namespace std;

//brute force
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        set<int> ans;
        for(int i = 0; i < n; i++){
            ans.insert(nums[i]);
        }

        int k = ans.size();
        int j = 0;
        for(int x : ans){
            nums[j] = x;
            j++;
        }

        return k;
    };
};

//better approach
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};