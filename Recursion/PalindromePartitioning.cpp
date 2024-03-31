#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
    void partitionHelper(string s, vector<vector<string>>& ans,
                         vector<string>& subset, int index) {
        if (index == s.size()) {
            ans.push_back(subset);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                subset.push_back(s.substr(index, i - index + 1));
                partitionHelper(s, ans, subset, i + 1);
                subset.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subset;
        partitionHelper(s, ans, subset, 0);
        return ans;
    }
};