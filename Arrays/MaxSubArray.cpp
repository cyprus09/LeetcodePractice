#include <climits>
#include <vector>
#include <algorithm>

using namespace std;


//first approach : brute force O(n^3)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentIndex = -1;

        for(int i = 0; i < nums.size(); i++){
            currentIndex = i;
            for(int j = currentIndex; j < nums.size(); j++){
    
                int sum = 0;
    
                for(int m = currentIndex; m <= j; m++){
                    sum += nums[m];
                }

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

//second approach : O(n^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentIndex = -1;

        for(int i = 0; i < nums.size(); i++){
            currentIndex = i;
            int sum = 0;
            for(int j = currentIndex; j < nums.size(); j++){
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

//third approach: O(n) : Kadane's Algorithm
class Solution {
public:
    long long maxSubArray(vector<int>& nums) {
        long long maxSum = LONG_MIN;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++){
            
            sum += nums[i];
            maxSum = max(maxSum, sum);

            if(sum < 0){
                sum = 0;
            }

        }

        return maxSum;
    }
};
