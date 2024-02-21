#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(nums.begin() + index + 1, nums.end());
            return;
        }

        for(int j = n - 1; j > index; j--){
            if(nums[index] < nums[j]){
                swap(nums[index], nums[j]);
                break;
            }
        }

        reverse(nums.begin() + index + 1, nums.end());

    }
};