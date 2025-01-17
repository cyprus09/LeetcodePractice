#include <vector>
#include <algorithm>

using namespace std;

/* intuition, keep swapping until you find a minimum value
example: 4325413 -> we can only change the last two numbers and have 432531
What if it was 432531 in the first place? 31 cannot be increased.
Lets try 531 - still no
2531 - this can be incrased - the smallest number that can be used to incrase
the 2 is 3. so for now we have 3521. Next we want to minimize 3521 - thats
easier - just sort the numbers to the right of 3 - 3125. So the unswer is
4323125 */
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int numIndex = n - 2;

        while (numIndex >= 0 && nums[numIndex + 1] <= nums[numIndex])
            numIndex--;

        if (numIndex < 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        for (int j = n - 1; j > numIndex; j--)
        {
            if (nums[j] > nums[numIndex])
            {
                swap(nums[numIndex], nums[j]);
                break;
            }
        }

        reverse(nums.begin() + numIndex + 1, nums.end());
        return;
    }
};