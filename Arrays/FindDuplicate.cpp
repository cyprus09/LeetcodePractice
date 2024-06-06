#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }

        return -1;
    }
};

// use this for nlogn approach
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<int> newVector;
        for (int i : nums)
        {
            newVector.push_back(i);
        }

        sort(newVector.begin(), newVector.end());

        for (int j = 1; j < newVector.size(); j++)
        {
            if (newVector[j - 1] == newVector[j])
            {
                return newVector[j];
            }
        }

        return -1;
    }
};

// best approach
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            if (freq[nums[i]] == 0)
            {
                freq[nums[i]] += 1;
            }
            else
            {
                return nums[i];
            }
        }
        return 0;
    }
};

// cyclic linked list approach (Floyd's Algorithm)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int slow2 = 0;

        while (slow != slow2)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow2;
    }
};