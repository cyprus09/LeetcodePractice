#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int count1 = 0, count2 = 0;
        int element1 = 0, element2 = 1;

        for(int num : nums){
            if(element1 == num){
                count1++;
            }else if(element2 == num){
                count2++;
            }else if(count1 == 0){
                element1 = num;
                count1 = 1;
            }else if(count2 == 0){
                element2 = num;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }

        int countOne = 0, countTwo = 0;
        for(int num : nums){
            if(num == element1){
                countOne++;
            }
            if(num == element2){
                countTwo++;
            }
        }

        if(countOne > nums.size() / 3){
            ans.push_back(element1);
        }

        if(countTwo > nums.size() / 3){
            ans.push_back(element2);
        }

        return ans;
    }
};