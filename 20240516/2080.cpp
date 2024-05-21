class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> data;
    int bucket = 0;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0;i < n;i++)
        {
            data[arr[i]].emplace_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(data.count(value) == 0)
        {
            return 0;
        }
        int index = lower_bound(data[value].begin(), data[value].end(), left) - data[value].begin();
        if(index == data[value].size())
        {
            return 0;
        }
        int index1 = upper_bound(data[value].begin(), data[value].end(), right) - data[value].begin();
        return index1-index;
    }
};