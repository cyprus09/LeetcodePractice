#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> storeValue;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storeValue[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(storeValue.find(key) == storeValue.end()){
            return "";
        }

        int low = 0, high = storeValue[key].size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(storeValue[key][mid].second < timestamp){
                low = mid + 1;
            }else if (storeValue[key][mid].second > timestamp){
                high = mid - 1;
            }else{
                return storeValue[key][mid].first;
            }
        }
        if(high >= 0){
            return storeValue[key][high].first;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */