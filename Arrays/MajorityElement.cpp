#include <map>
#include <vector>

using namespace std;

//moore's voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element){
                count++;
            }else{
                if(count == 0){
                    element = nums[i];
                    count = 2;
                }
                count--;
            }
        }

        int elemCount = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == element){
                elemCount++;
            }
            if(elemCount > nums.size()/2){
                return element;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto it : mpp) {
            if (it.second > (n / 2)) {
                return it.first;
            }
        }

        return -1;
    }
};