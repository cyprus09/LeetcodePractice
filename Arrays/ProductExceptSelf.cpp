#include <vector>

using namespace std;

// naive approach is to use division operator but goal it not do that
// another naive approach (brute force)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int product = 1;
            if (i == 0)
            {
                for (int j = 1; j < nums.size(); j++)
                {
                    product *= nums[j];
                }
                ans.push_back(product);
                continue;
            }
            else if (i == nums.size())
            {
                for (int j = 0; j < nums.size() - 1; j++)
                {
                    product *= nums[j];
                }
                ans.push_back(product);
                continue;
            }
            else
            {
                for (int j = 0; j < i; j++)
                {
                    product *= nums[j];
                }
                for (int j = i + 1; j < nums.size(); j++)
                {
                    product *= nums[j];
                }
                ans.push_back(product);
            }
        }
        return ans;
    }
};

// better approach to solve in O(n) time complexity
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prefixProduct = 1, n = nums.size();
        vector<int> result(n, 1);

        for (int i = 0; i < n - 1; i++)
        {
            result[i + 1] = prefixProduct * nums[i];
            prefixProduct *= nums[i];
        }

        prefixProduct = 1;
        for (int i = n - 1; i > 0; i--)
        {
            result[i - 1] *= prefixProduct * nums[i];
            prefixProduct *= nums[i];
        }

        return result;
    }
};