#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
private:
  bool dfs(int course, unordered_map<int, vector<int>> &m,
           unordered_set<int> &visited, unordered_set<int> &cycle,
           vector<int> &result)
  {
    if (visited.find(course) != visited.end())
      return true;

    if (cycle.find(course) != cycle.end())
      return false;

    cycle.insert(course);

    for (int i = 0; i < m[course].size(); i++)
    {
      int nextCourse = m[course][i];
      if (!dfs(nextCourse, m, visited, cycle, result))
        return false;
    }
    cycle.erase(course);
    visited.insert(course);
    result.push_back(course);
    return true;
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < prerequisites.size(); i++)
      m[prerequisites[i][0]].push_back(prerequisites[i][1]);

    unordered_set<int> visit;
    unordered_set<int> cycle;
    vector<int> result;

    for (int i = 0; i < numCourses; i++)
    {
      if (!dfs(i, m, visit, cycle, result))
        return {};
    }
    return result;
  }
};