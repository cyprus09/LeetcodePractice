#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> letter;
        int maxFreq = 0;

        int leftPtr = 0, rightPtr = 0;
        int res = 0;

        while (rightPtr < s.size())
        {
            letter[s[rightPtr]]++;
            maxFreq = max(maxFreq, letter[s[rightPtr]]);
            if (rightPtr - leftPtr + 1 - maxFreq > k)
            {
                letter[s[leftPtr]]--;
                leftPtr++;
            }
            res = max(res, rightPtr - leftPtr + 1);
            rightPtr++;
        }
        return res;
    }
};