#include <string>
#include <vector>

using namespace std;

// expand around center algo
class Solution
{
public:
  string longestPalindrome(string s)
  {
    int start = 0, maxLen = 1;

    if (s.empty())
      return "";

    for (int i = 0; i < s.size(); i++)
    {
      // even palindromes
      int l = i, r = i;
      while (l >= 0 && r < s.size() && s[l] == s[r])
        l--, r++;
      l++, r--;
      int currLen = r - l + 1;
      if (currLen > maxLen)
      {
        start = l;
        maxLen = currLen;
      }

      // odd palindromes
      l = i, r = i + 1;
      while (l >= 0 && r < s.size() && s[l] == s[r])
        l--, r++;
      l++, r--;
      currLen = r - l + 1;
      if (currLen > maxLen)
      {
        start = l;
        maxLen = currLen;
      }
    }

    return s.substr(start, maxLen);
  }
};