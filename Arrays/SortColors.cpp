#include <vector>

using namespace std;

//approach one
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numZeroes = 0;
        int numOnes = 0;
        int numTwos = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                numZeroes++;
            }else if(nums[i] == 1){
                numOnes++;
            }else if(nums[i] == 2){
                numTwos++;
            }
        }

        for(int i = 0; i < numZeroes; i++){
            nums[i] = 0;
        }
        for(int i = numZeroes; i < numZeroes + numOnes; i++){
            nums[i] = 1;
        }
        for(int i = numZeroes + numOnes; i < nums.size(); i++){
            nums[i] = 2;
        }
    }
};

//approach two : three pointer approach
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
            }
            if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }else{
                mid++;
            }
        }
    }
};