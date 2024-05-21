class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int mxindexG = 0;
        int mxindexP = 0;
        int mxindexM = 0;
        int n = garbage.size();
        int ret = 0;

        for(int i = 0;i < n;i++)
        {
            for(char ch:garbage[i])
            {
                if(ch == 'G')
                {
                    mxindexG = i;
                    continue;
                }
                if(ch == 'P')
                {
                    mxindexP = i;
                    continue;
                }
                if(ch == 'M')
                {
                    mxindexM = i;
                    continue;
                }
            }
            ret += garbage[i].size();
        }
        vector<int> indexs;
        indexs.push_back(mxindexG);
        indexs.push_back(mxindexP);
        indexs.push_back(mxindexM);
        sort(indexs.begin(), indexs.end());
        int sum = 0;
        int i = 0;
        for(int ix:indexs)
        {
            while(i < ix)
            {
                sum += travel[i];
                i++;
            }
            ret += sum;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/description/