#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> stackChars;
        for(char c : s){
            if(isalnum(c)){
                stackChars.push(tolower(c));
            }
        }

        for(char c : s){
            if(isalnum(c)){
                char stackTop = stackChars.top();
                stackChars.pop();
                if(tolower(c) != stackTop) {
                    return false;
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; int right = s.length() - 1;
        while(left < right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }

        return true;
    }
};