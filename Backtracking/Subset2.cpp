#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if ((i >> j) & 1)
                    temp.push_back(nums[j]);
            }

            sort(temp.begin(), temp.end());
            if (count(ans.begin(), ans.end(), temp) == 0)
                ans.push_back(temp);
        }

        return ans;
    }
};

// optimal approach
// sort before putting in the set so no duplicates are entered for sure
class Solution
{
private:
    void subsetHelper(vector<int> &nums, set<vector<int>> &result, vector<int> &subset, int i)
    {
        if (i == nums.size())
        {
            sort(subset.begin(), subset.end());
            result.insert(subset);
            return;
        }

        subset.push_back(nums[i]);
        subsetHelper(nums, result, subset, i + 1);

        subset.pop_back();
        subsetHelper(nums, result, subset, i + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        set<vector<int>> ans;
        vector<int> subset;

        subsetHelper(nums, ans, subset, 0);
        // it is a pointer to the value, hence have to dereference it to access to push_back()
        for (auto it = ans.begin(); it != ans.end(); it++)
        {
            result.push_back(*it);
        }
        return result;
    }
};