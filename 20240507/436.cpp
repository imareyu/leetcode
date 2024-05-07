class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> intervalsPair;
        map<pair<int,int>, int> indexMap;
        int n = intervals.size();

        for(int i = 0;i < n;i++)
        {
            intervalsPair.emplace_back(intervals[i][0], intervals[i][1]);
            indexMap[make_pair(intervals[i][0], intervals[i][1])] = i;
        }

        sort(intervalsPair.begin(), intervalsPair.end());

        vector<int> ret(n, -1);
        for(int i = 0;i < n;i++)
        {
            int be = intervals[i][0];
            int en = intervals[i][1];
            if(be == en)
            {
                ret[i] = indexMap[make_pair(be, en)];
            }
            else
            {
                auto index = lower_bound(intervalsPair.begin(), intervalsPair.end(), make_pair(en,INT_MIN));
                if(index != intervalsPair.end())
                {
                    ret[i] = indexMap[make_pair(index->first, index->second)];
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/find-right-interval/description/