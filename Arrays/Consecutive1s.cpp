#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                right++;
            } else {
                maxCount = max(maxCount, right - left);
                left = i + 1;
                right = i + 1;
            }
        }
        maxCount = max(maxCount, right - left);
        return maxCount;
    }
};