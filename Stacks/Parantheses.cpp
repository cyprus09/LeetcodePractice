#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;

        for (auto it : s) {
            if (it == '(' || it == '{' || it == '[') {
                bracket.push(it);
            } else {
                if (bracket.empty() || (it == ')' && bracket.top() != '(') ||
                    (it == '}' && bracket.top() != '{') ||
                    (it == ']' && bracket.top() != '[')) {
                    return false;
                }
                bracket.pop();
            }
        }
        return bracket.empty();
    }
};