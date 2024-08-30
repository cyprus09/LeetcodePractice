#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
private:
  void letterHelper(vector<string> &result, string digits, string &curr, int index,
                    unordered_map<char, string> &letters)
  {
    if (index == digits.size())
    {
      result.push_back(curr);
      return;
    }

    string str = letters[digits[index]];
    for (int i = 0; i < str.size(); i++)
    {
      curr.push_back(str[i]);
      letterHelper(result, digits, curr, index + 1, letters);
      curr.pop_back();
    }
  }

public:
  vector<string> letterCombinations(string digits)
  {
    if (digits.empty())
      return {};

    unordered_map<char, string> letters =
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

    string curr = "";
    vector<string> result;
    letterHelper(result, digits, curr, 0, letters);
    return result;
  }
};