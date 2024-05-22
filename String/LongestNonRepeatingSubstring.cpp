#include <climits>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

// optimal approach
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
        {
            return 0;
        }
        int leftPointer = 0, rightPointer = 0;
        unordered_set<char> substr;
        int maxLen = 0;

        while (rightPointer < s.length())
        {
            if (substr.find(s[rightPointer]) == substr.end())
            {
                substr.insert(s[rightPointer]);
                rightPointer++;
                maxLen = max(maxLen, rightPointer - leftPointer);
            }
            else
            {
                substr.erase(s[leftPointer]);
                leftPointer++;
            }
        }
        return maxLen;
    }
};