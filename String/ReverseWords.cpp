#include <vector>

using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    vector<string> words;
    string currWord = "";

    for (int i = 0; i <= s.size(); i++)
    {
      if (i == s.size() || s[i] == ' ')
      {
        if (!currWord.empty())
        {
          words.push_back(currWord);
          currWord = "";
        }
      } 
      else
      {
        currWord += s[i];
      }
    }

    string result = "";
    for (int i = words.size() - 1; i >= 0; i--)
    {
      result += words[i];
      if (i > 0)
        result += " ";
    }

    return result;
  }
};