#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//bit manipulation for generating power set
vector<int> subsetSum(vector<int> &num) {
  int n = num.size();
  vector<int> subset_sums;  

  for (int i = 0; i < (1 << n); i++) {
    int current_sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        current_sum += num[j];
      }
    }
    subset_sums.push_back(current_sum); 
  }

  return subset_sums;
}

//recursive approach
void findSum(int index, vector<int> &num, vector<int> &ans, int sum){
	if(index == num.size()){
		ans.push_back(sum);
		return;
	}

	findSum(index + 1, num, ans, sum + num[index]);
	findSum(index + 1, num, ans, sum);
}

vector<int> subsetSum(vector<int> &num){
	vector<int> ans;
	findSum(0, num, ans, 0);
	sort(ans.begin(), ans.end());
	return ans;
}