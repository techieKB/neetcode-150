class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>values;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        values[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& vals = values[key];
        int left = 0, right = vals.size() - 1;
        int ans = INT_MAX;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(vals[mid].first > timestamp){
                right = mid - 1;
            } else if(vals[mid].first <= timestamp){
                ans = mid;
                left = mid + 1;
            }
        }
        return ans == INT_MAX ? "" : vals[ans].second ;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */