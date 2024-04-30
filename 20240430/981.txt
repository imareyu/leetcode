class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data;//key  pair<time,val>
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(data.count(key) == 0)//找不到
            return "";
        pair<int, string> pa;
        pa.first = timestamp;
        pa.second = "";
        int index = upper_bound(data[key].begin(), data[key].end(), pa) - data[key].begin();
        if(index >= 0 && index < data[key].size() && data[key][index].first <= timestamp)
            return data[key][index].second;
        index--;
        if(index >= 0 && index < data[key].size() && data[key][index].first <= timestamp)
            return data[key][index].second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
//https://leetcode.cn/problems/time-based-key-value-store/