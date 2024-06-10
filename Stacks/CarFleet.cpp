#include <vector>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i = 0; i < n; i++){
            double time = (double) (target - position[i]) / (speed[i]);
            cars.push_back({position[i], time});
        }

        int maxTime = 0.0;
        int numFleets = 0;

        for(int i = n - 1; i >= 0; i--){
            if(maxTime < cars[i].second){
                maxTime = cars[i].second;
                numFleets++;
            }
        }
        return numFleets;
    }
};