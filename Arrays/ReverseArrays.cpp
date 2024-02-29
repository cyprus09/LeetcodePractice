#include <vector>

using namespace std;

//brute force approach
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if((long long)nums[i] > 2 * (long long)nums[j]) {
                    count++;
                }
            }
        }
        
        return (int)count;
    }
};


//optimal approach

