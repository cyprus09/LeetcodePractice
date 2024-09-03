#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
  {
    set<int> nums;
    for (int i = 0; i < triplets.size(); i++)
    {
      if (triplets[i][0] > target[0] || triplets[i][1] > target[1] ||
          triplets[i][2] > target[2])
        continue;
      for (int j = 0; j < 3; j++)
      {
        if (target[j] == triplets[i][j])
          nums.insert(j);
      }
    }
    return nums.size() == 3;
  }
};