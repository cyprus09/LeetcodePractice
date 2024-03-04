#include <climits>
#include <unordered_set>
#include <algorithm>
#include <string>


using namespace std;

//optimal approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        int maxAns = INT_MIN;
        unordered_set<int> st;
        int left = 0;

        for(int right = 0; right < s.length(); right++){
            if(st.find(s[right]) != st.end()){
                while(left < right && st.find(s[right]) != st.end()){
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
            maxAns = max(maxAns, right - left + 1);
        }

        return maxAns;
    }
};