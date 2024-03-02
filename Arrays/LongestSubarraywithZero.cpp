#include <vector>

using namespace std;

int LongestSubsetWithZeroSum(vector<int> &arr) {
  int maxi = 0;
  int sum = 0;
  unordered_map<int, int> mpp;

  for(int i = 0; i < arr.size(); i++){
    sum += arr[i];
    if(sum == 0){
      maxi = i + 1;
    }
    else if(mpp.find(sum) != mpp.end()){
      maxi = max(maxi, i - mpp[sum]);
    }else{
      mpp[sum] = i;
    }
  }
  return maxi;
}