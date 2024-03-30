#include <algorithm>
#include <vector>

using namespace std;

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