#include <iostream>
#include <vector>

using namespace std;

vector<int> MinimumCoins(int n) {
    vector<int> ans;
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    for(int i = denominations.size() - 1; i >= 0; i--){
        while(n >= denominations[i]){
            n -= denominations[i];
            ans.push_back(denominations[i]);
            if(n == 0) break;
        }
    }

    return ans;
}