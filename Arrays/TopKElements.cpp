#include <queue>
#include <unordered_map>

using namespace std;

// approach could be to use heapify and add elements from the
// unordered map with key as the frequency and then pop until k = 0
// O(nlogk), O(n + k)
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto it : m)
        {
            pq.push({it.second, it.first});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};

// optimise by
// bucket sort approach taking freq cannot be > n; (O(n), O(n) time and space complexity)
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int it : nums)
        {
            mp[it]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for (auto it : mp)
        {
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for (int i = nums.size(); i >= 0; i--)
        {
            if (ans.size() >= k)
            {
                break;
            }
            if (!bucket[i].empty())
            {
                ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
            }
        }

        return ans;
    }
};