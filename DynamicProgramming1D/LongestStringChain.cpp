#include <vector>

using namespace std;

class Solution
{
private:
  bool compare(string &s1, string &s2)
  {
    if (s1.size() != s2.size() + 1)
      return false;
    int first = 0, second = 0;

    while (first < s1.size())
    {
      if (second < s2.size() && s1[first] == s2[second])
      {
        first++, second++;
        continue;
      }
      first++;
    }

    if (second == s2.size())
      return true;

    return false;
  }

  static bool cmp(const string &s1, const string &s2)
  {
    return s1.size() < s2.size();
  }

public:
  int longestStrChain(vector<string> &words)
  {
    int n = words.size();
    vector<int> dp(n, 1);

    sort(words.begin(), words.end(), cmp);
    int max = -1;

    for (int i = 0; i < n; i++)
    {
      for (int prev = 0; prev < i; prev++)
      {
        if (compare(words[i], words[prev]) && 1 + dp[prev] > dp[i])
          dp[i] = 1 + dp[prev];
      }
      if (dp[i] > max)
        max = dp[i];
    }

    return max;
  }
};