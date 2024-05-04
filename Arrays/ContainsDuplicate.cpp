#include <unordered_map>
#include <vector>

using namespace std;

// O(n) approach
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto it : nums)
        {
            freq[it]++;
        }
        for (auto it : freq)
        {
            if (it.second >= 2)
                return true;
        }
        return false;
    }
};
