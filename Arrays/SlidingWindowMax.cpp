#include <vector>
#include <deque>

using namespace std;

//naive approach : O(n^2)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;

        if (nums.empty() || k <= 0) {
            return answer;
        }

        for (int i = 0; i <= nums.size() - k; i++) {
            int max = nums[i];
            for (int j = i; j < i + k; j++) {
                if (nums[j] > max) {
                    max = nums[j];
                }
            }
            answer.push_back(max);
        }
        return answer;
    }
};

//better approach : O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> answer;
        if (nums.empty() || k <= 0)
            return answer;

        deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                answer.push_back(nums[dq.front()]);
            }
        }

        return answer;
    }
};