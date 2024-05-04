#include <unordered_map>
#include <string>
using namespace std;

// naive approach to count number of characters
// O(n) = O(s + t) time complexity
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> ans;

        if (s.size() != t.size())
        {
            return false;
        }

        for (char c : s)
        {
            ans[c]++;
        }
        for (char c : t)
        {
            if (ans.find(c) == ans.end() || ans[c] == 0)
            {
                return false;
            }
            ans[c]--;
        }
        for (const auto &pair : ans)
        {
            if (pair.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

#include <algorithm>

// another approach using O(nlogn) approach by sorting and comparing
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
            {
                return false;
            }
        }

        return true;
    }
};
