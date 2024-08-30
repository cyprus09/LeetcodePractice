#include <vector>

using namespace std;

// recursive approach
class Solution
{
private:
    void helper(vector<vector<int>> &result, vector<int> &subset,
                vector<int> &nums, int frequency[])
    {
        if (subset.size() == nums.size())
        {
            result.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!frequency[i])
            {
                subset.push_back(nums[i]);
                frequency[i] = 1;
                helper(result, subset, nums, frequency);
                frequency[i] = 0;
                subset.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        int frequency[nums.size()];

        for (int i = 0; i < nums.size(); i++)
            frequency[i] = 0;
        helper(result, subset, nums, frequency);
        return result;
    }
};

// backtracking approach
class Solution
{
private:
    void helper(vector<vector<int>> &result, vector<int> &nums, int start)
    {
        if (start == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[i], nums[start]);
            helper(result, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        helper(result, nums, 0);
        return result;
    }
};