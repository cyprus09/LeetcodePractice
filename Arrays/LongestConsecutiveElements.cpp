#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());

        int currentStreak = 1, longestStreak = 1;

        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i] == nums[i + 1])
            {
                continue;
            }

            if (nums[i] + 1 == nums[i + 1])
            {
                currentStreak++;
            }
            if (nums[i] + 1 != nums[i + 1])
            {
                longestStreak = max(currentStreak, longestStreak);
                currentStreak = 1;
            }
        }

        return max(currentStreak, longestStreak);
    }
};