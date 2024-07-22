#include <string>

using namespace std;

// middle out approach for longest palindrome

/* talk bout the main naive approach of coding in O(n3) where i use each substring,
then i end up optimising it by splitting even and odd characters in two while loops,
then use the following which also O(n2) but better approach */

class Solution
{
private:
  void middleOut(string s, int i, int j, int &maxStart, int &maxLength)
  {
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
      i--;
      j++;
    }
    if (j - i - 1 > maxLength)
    {
      maxStart = i + 1;
      maxLength = j - i - 1;
    }
  }

public:
  string longestPalindrome(string s)
  {
    int maxStart = 0, maxLength = 1;

    for (int i = 0; i < s.size() - 1; i++)
    {
      middleOut(s, i, i, maxStart, maxLength);
      middleOut(s, i, i + 1, maxStart, maxLength);
    }
    return s.substr(maxStart, maxLength);
  }
};