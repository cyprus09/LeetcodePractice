#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//not the most optimal approach but still covers most cases
struct Jobs {
  int id;
  int deadline;
  int profit;
};

bool comparator(const Jobs &j1, const Jobs &j2) {
  return j1.profit > j2.profit;
}

vector<int> jobScheduling(vector<vector<int>> &jobs) {
  vector<int> ans;
  Jobs jobSchedule[jobs.size()];
  for (int i = 0; i < jobs.size(); i++) {
    jobSchedule[i].id = jobs[i][0];
    jobSchedule[i].deadline = jobs[i][1];
    jobSchedule[i].profit = jobs[i][2];
  }

  sort(jobSchedule, jobSchedule + jobs.size(), comparator);
  int maxi = jobSchedule[0].deadline;
  for (int i = 0; i < jobs.size(); i++) {
    maxi = max(maxi, jobSchedule[i].deadline);
  }

  vector<int> slot(maxi + 1, -1);

  int countJobs = 0, profit = 0;

  for (int i = 0; i < jobs.size(); i++) {
    for (int j = jobSchedule[i].deadline; j > 0; j--) {
      if (slot[j] == -1) {
        slot[j] = i;
        countJobs++;
        profit += jobSchedule[i].profit;
        break;
      }
    }
  }

  ans.push_back(countJobs);
  ans.push_back(profit);

  return ans;
}

//can use lamba comparator to sort the jobs instead of using an extra array
vector<int> jobScheduling(vector<vector<int>> &jobs) {
  vector<int> ans;

  sort(jobs.begin(), jobs.end(),
       [](const vector<int> &j1, const vector<int> &j2) {
         return j1[2] > j2[2];
       });

  int maxi = jobs[0][1];
  for (int i = 0; i < jobs.size(); i++) {
    maxi = max(maxi, jobs[i][1]);
  }

  vector<int> slot(maxi + 1, -1);

  int countJobs = 0, profit = 0;

  for (int i = 0; i < jobs.size(); i++) {
    for (int j = jobs[i][1]; j > 0; j--) {
      if (slot[j] == -1) {
        slot[j] = i;
        countJobs++;
        profit += jobs[i][2];
        break;
      }
    }
  }

  ans.push_back(countJobs);
  ans.push_back(profit);

  return ans;
}

//decent approach
bool comp(vector<int> a, vector<int> b){
    return a[2] > b[2];
}

vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int count = 0, profit = 0;
    int n = jobs.size();
    vector<int> temp(n + 1, -1);
    sort(jobs.begin(), jobs.end(), comp);
    for(int i = 0; i < n; i++){
        for(int j = jobs[i][1]; j > 0; j--){
            if(temp[j] == -1){
                temp[j] = jobs[i][2];
                profit += jobs[i][2];
                count++;
                break;
            }
        }
    }

    return {count, profit};
}