#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#include <algorithm>

struct Timings
{
    int start;
    int end;
};

bool static comparator(Timings t1, Timings t2) { return t1.end < t2.end; }

int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int count = 1;
    int n = start.size();

    Timings activities[n];

    for (int i = 0; i < n; i++)
    {
        activities[i].start = start[i];
        activities[i].end = finish[i];
    }

    sort(activities, activities + n, comparator);

    int limit = activities[0].end;

    for (int i = 1; i < n; i++)
    {
        if (limit > activities[i].start)
        {
            continue;
        }
        else
        {
            limit = activities[i].end;
            count++;
        }
    }

    return count;
}