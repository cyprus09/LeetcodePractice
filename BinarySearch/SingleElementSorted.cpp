#include <unordered_map>
#include <vector>

using namespace std;

// non-optimal approach
int singleNonDuplicate(vector<int> &arr)
{
    unordered_map<int, int> nums;
    for (auto i : arr)
    {
        if (nums.find(i) != nums.end())
        {
            nums[i] += 1;
            continue;
        }
        nums[i] = 1;
    }

    for (auto i : nums)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }
    return -1;
}

// xor approach
int singleNonDuplicate(vector<int> &arr)
{
    int ans = 0;
    for (auto i : arr)
    {
        ans ^= i;
    }

    return ans;
}

// binary search approach (most optimal)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};