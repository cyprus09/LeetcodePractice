#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

//optimal approach
class Solution {
private:
    bool isPermutation(vector<int> &count){
        for(int i = 0; i < 26; i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> temp1;
        unordered_map<char, int> temp2;

        vector<int> count(26);
        for(int i = 0; i < s1.size(); i++){
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }

        if(isPermutation(count)){
            return true;
        }

        for(int i = s1.size(); i < s2.size(); i++){
            count[s2[i] - 'a']--;
            count[s2[i - s1.size()] - 'a']++;
            if(isPermutation(count)){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> ans;
        unordered_map<char, int> temp;
        if (s1.length() > s2.length()) {
            return false;
        }

        for (int i = 0; i < s1.length(); i++) {
            ans[s1[i]]++;
            temp[s2[i]]++;
        }
        int j = 0;
        bool flag = true;
        for (auto s : ans) {
            if (s.second != temp[s.first]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            return true;
        }
        flag = true;
        for (int i = s1.length(); i < s2.length(); i++) {
            temp[s2[i]]++;
            temp[s2[j]]--;
            j++;
            for (auto s : ans) {
                if (s.second != temp[s.first]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                return true;
            }
            flag = true;
        }
        return false;
    }
};