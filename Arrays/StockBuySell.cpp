#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;

        int minPrice = INT_MAX;

        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, left = 0, right = 1, diff = 0;
        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                diff = prices[right] - prices[left];
                maxProfit = max(maxProfit, diff);
            }else{
                left = right;
            }
            right++;
        }
        return maxProfit;
    }
};