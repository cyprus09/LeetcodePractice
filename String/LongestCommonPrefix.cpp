#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    sort(strs.begin(), strs.end());

    string ans = "";
    int n = strs.size();
    string first = strs[0], last = strs[n - 1];
    int minSize = min(first.size(), last.size());

    for (int i = 0; i < minSize; i++)
    {
      if (first[i] != last[i])
        return ans;
      ans += first[i];
    }
    return ans;
  }
};