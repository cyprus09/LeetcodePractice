#include <string>

using namespace std;

class Solution
{
private:
  void substringHelper(string s, int i, int j, int &result)
  {
    while (i >= 0 && j < s.size() && s[i] == s[j])
      result++, i--, j++;
  }

public:
  int countSubstrings(string s)
  {
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
      substringHelper(s, i, i, result);
      substringHelper(s, i, i + 1, result);
    }
    return result;
  }
};