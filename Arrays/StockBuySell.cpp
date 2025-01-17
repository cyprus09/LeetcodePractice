#include <climits>
#include <vector>

using namespace std;

// brute force solution
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            int diff = 0;
            for (int j = i + 1; j < prices.size(); j++)
            {
                diff = prices[j] - prices[i];
                if (diff > maxProfit)
                    maxProfit = diff;
            }
        }

        return maxProfit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;

        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

// two pointers solution: maintain L and R
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0, right = 1, diff = 0, maxProfit = 0;

        while (right < prices.size())
        {
            diff = prices[right] - prices[left];
            if (diff < 0)
                left = right;
            if (diff >= 0)
                maxProfit = max(diff, maxProfit);
            right++;
        }

        return maxProfit;
    }
};