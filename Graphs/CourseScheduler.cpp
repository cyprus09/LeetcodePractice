#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
private:
  bool dfs(int course, unordered_map<int, vector<int>> &m,
           unordered_set<int> &visited)
  {
    if (visited.find(course) != visited.end())
      return false;
    if (m[course].empty())
      return true;
    visited.insert(course);
    for (int i = 0; i < m[course].size(); i++)
    {
      int nextCourse = m[course][i];
      if (!dfs(nextCourse, m, visited))
        return false;
    }
    m[course].clear();
    visited.erase(course);
    return true;
  }

public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
  {
    unordered_map<int, vector<int>> m;
    unordered_set<int> visited;

    for (int i = 0; i < prerequisites.size(); i++)
      m[prerequisites[i][0]].push_back(prerequisites[i][1]);

    for (int course = 0; course < numCourses; course++)
    {
      if (!dfs(course, m, visited))
        return false;
    }
    return true;
  }
};