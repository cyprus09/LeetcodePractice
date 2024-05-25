#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> window;
        for (int i = 0; i < t.size(); i++)
        {
            window[t[i]]++;
        }

        int i = 0, j = 0;

        int counter = t.size();
        int minStart = 0;
        int minLength = INT_MAX;

        while (j < s.size())
        {
            if (window[s[j]] > 0)
            {
                counter--;
            }

            window[s[j]]--;
            j++;

            while (counter == 0)
            {
                if (j - i < minLength)
                {
                    minStart = i;
                    minLength = j - i;
                }

                window[s[i]]++;

                if (window[s[i]] > 0)
                {
                    counter++;
                }
                i++;
            }
        }

        if (minLength != INT_MAX)
        {
            return s.substr(minStart, minLength);
        }
        return "";
    }
};