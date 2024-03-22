#include <iostream>
#include <vector>

using namespace std;

struct Meeting{
    int start;
    int end;
    int pos;
};

bool comparator(struct Meeting m1, struct Meeting m2){
    if(m1.end < m2.end) return true;
    if(m1.end > m2.end) return false;
    if(m1.pos < m2.pos) return true;
}

int maximumMeetings(vector<int> &start, vector<int> &end){

    struct Meeting meet[end.size()];
    for(int i = 0; i < end.size(); i++){
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }

    sort(meet, meet + end.size(), comparator);

    int limit = meet[0].end;
    int count = 1;
    
    for(int i = 1; i < end.size(); i++){
        if(limit < meet[i].start){
            limit = meet[i].end;
            count++;
        }
    }

    return count;
}