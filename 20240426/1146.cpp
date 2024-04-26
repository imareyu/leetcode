class SnapshotArray {
private:
    int len = 0;
    int snap_id = 0;
    unordered_map<int,vector<int>> indexChange;
    map<pair<int,int>, int> data;
public:
    SnapshotArray(int length) {
        len = length;
    }
    
    void set(int index, int val) {
        indexChange[index].push_back(snap_id);
        data[make_pair(index,snap_id)] = val;
    }
    
    int snap() {
        int ret = snap_id;
        snap_id++;
        return ret;
    }
    
    int get(int index, int snap_id) {
        if(indexChange[index].size() == 0)
            return 0;
        auto it = upper_bound(indexChange[index].begin(), indexChange[index].end(), snap_id);
        if(it != indexChange[index].begin())
        {
            it--;
            return data[make_pair(index,*it)];
        }
        return 0;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
//https://leetcode.cn/problems/snapshot-array/?envType=daily-question