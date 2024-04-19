#include <vector> 

using namespace std;

bool isPossible(long long n, long long m, vector<int> time, long long mid){
    long long chapter = 0;
    long long dayCount = 1;

    for(long long i = 0; i < m; i++){
        if(chapter + time[i] <= mid){
            chapter += time[i];
        }else{
            dayCount++;
            if(dayCount > n || time[i] > mid){
                return false;
            }
            chapter = time[i];
        }
    }

    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long s = 0;
    long long sum = 0;
    long long ans = 1;

    for(long long i = 0; i < m; i++){
        sum += time[i];
    }
    long long e = sum;
    while(s <= e){
        long long mid = s + (e - s) / 2;
        if(isPossible(n, m, time, mid)){
            ans = mid;
            e = mid - 1;
        }else{
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}