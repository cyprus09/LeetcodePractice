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

// binary search approach
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }

        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
            (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}