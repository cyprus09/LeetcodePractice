#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int index = st.top();
                st.pop();
                result[index] = i - index;
            }
            st.push(i);
        }
        return result;
    }
};