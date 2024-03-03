#include <vector>

using namespace std;

int subarraysWithSumK(vector < int > a, int b) {
    int count = 0;
    int n = a.size();

    for(int i = 0; i < n; i++){
        int xorValue = 0;
        for(int j = i; j < n; j++){
            xorValue ^= a[j];

            if(xorValue == b) count++;
        }
    }

    return count;
}

//better approach
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int count = 0;
    int xorSum = 0;

    unordered_map<int, int> xorPrefixCount;
    xorPrefixCount[0] = 1;

    for(int i = 0; i < n; i++){
        xorSum ^= a[i];

        int targetXor = b ^ xorSum;

        if(xorPrefixCount.find(targetXor) != xorPrefixCount.end()){
            count += xorPrefixCount[targetXor];
        }

        xorPrefixCount[xorSum]++;
    }

    return count;
}