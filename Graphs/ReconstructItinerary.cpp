#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    void findItineraryHelper(unordered_map<string, multiset<string> >& m, string airport, vector<string>& result) {
        while (!m[airport].empty()) {
            string nextAirport = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            findItineraryHelper(m, nextAirport, result);
        }
        result.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string> >& tickets) {
        unordered_map<string, multiset<string> > m;
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }

        vector<string> result;
        findItineraryHelper(m, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<vector<string> > tickets;
    tickets.push_back({"MUC", "LHR"});
    tickets.push_back({"JFK", "MUC"});
    tickets.push_back({"SFO", "SJC"});
    tickets.push_back({"LHR", "SFO"});

    Solution solution;
    
    vector<string> itinerary = solution.findItinerary(tickets);

    for (const string& airport : itinerary) {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}