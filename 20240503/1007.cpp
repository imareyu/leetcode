class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<set<int>> count1(6);
        vector<set<int>> count2(6);

        for(int i = 0;i < tops.size();i++)
        {
            count1[tops[i]-1].insert(i);
        }
        for(int i = 0;i < bottoms.size();i++)
        {
            count2[bottoms[i]-1].insert(i);
        }
        //算一下最小的
        vector<int> sums;
        for(int i = 0;i < 6;i++)
        {
            if(count1[i].size() + count2[i].size() >= n)
            {
                sums.push_back(i);
            }
        }
        int ret = INT_MAX;
        for(int i = 0;i < sums.size();i++)
        {
            set<int> co(count1[sums[i]].begin(), count1[sums[i]].end());
//            co.insert(count1[sums[i]].begin(), count1[sums[i]].end());
            co.insert(count2[sums[i]].begin(), count2[sums[i]].end());
            if(co.size() == n)
            {
                ret = min(n-(int)count1[sums[i]].size(), ret);
                ret = min(n-(int)count2[sums[i]].size(), ret);
            }
        }
        if(ret == INT_MAX)
            ret = -1;
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-domino-rotations-for-equal-row/description/