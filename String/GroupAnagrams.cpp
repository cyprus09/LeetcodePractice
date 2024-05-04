#include <algorithm>
#include <unordered_map>
#include<string>
#include<vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> anagramGroup;

        for (const string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());

            if (anagramGroup.find(key) == anagramGroup.end())
            {
                anagramGroup[key] = {str};
            }

            else
            {
                anagramGroup[key].push_back(str);
            }
        }

        for (const auto &group : anagramGroup)
        {
            ans.push_back(group.second);
        }

        return ans;
    }
};