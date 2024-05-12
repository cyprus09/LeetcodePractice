#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> answer;
        unordered_map<int, int> nums;

        for (int i = 0; i < numbers.size(); i++)
        {
            int targetSum = target - numbers[i];
            if (nums.find(targetSum) != nums.end())
            {
                answer.push_back(nums[targetSum] + 1);
                answer.push_back(i + 1);
                return answer;
            }
            nums[numbers[i]] = i;
        }

        return answer;
    }
};