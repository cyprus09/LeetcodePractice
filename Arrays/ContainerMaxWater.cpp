#include <vector>

using namespace std;

//best solution with O(n) and O(1) approach
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        // maxArea of rect = width * height
        // height is array passed, and width is distance between two heights
        // take two points, left and right
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        int heightToBeTaken = 0;
        int area = 0;

        while (left < right)
        {
            heightToBeTaken = min(height[left], height[right]);
            area = (right - left) * heightToBeTaken;
            maxArea = max(maxArea, area);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxArea;
    }
};