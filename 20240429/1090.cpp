class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        map<pair<int,int>, int> data;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, less<tuple<int,int,int>>> pq;

        for(int i = 0;i < values.size();i++)
        {
            data[make_pair(values[i], labels[i])]++;
        }

        for(auto& [pa, count]: data)
        {
            auto& [v, l] = pa;
            pq.push(make_tuple(v, l, count));
        }
        int ret = 0;
        unordered_map<int,int> used;//label已经使用的次数
        while(numWanted)
        {
            if(pq.empty())
                break;
            auto [value, label, count] = pq.top();
            pq.pop();
            int addCount = min(numWanted, useLimit);
            addCount = min(addCount, count);
            if(used.count(label) > 0)
                addCount = min(addCount, useLimit-used[label]);
            used[label] += addCount;
            ret += addCount * value;
            numWanted -= addCount;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/largest-values-from-labels/description/