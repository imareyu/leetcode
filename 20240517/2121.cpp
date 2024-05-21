class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        vector<long long> ret(n, 0);
        unordered_map<int,vector<long long>> indexs;

        for(int i = 0;i < n;i++)
        {
            indexs[arr[i]].emplace_back(i);
        }

        for(auto& [val, indexVec] : indexs)
        {
            int vecSize = indexVec.size();
            if(vecSize == 1)
                continue;
            vector<long long> pre(vecSize, 0);
            pre[0] = indexVec[0];
            for(int i = 1;i < vecSize;i++)
            {
                pre[i] = pre[i-1] + indexVec[i];
            }
            ret[indexVec[0]] = pre[vecSize-1] - pre[0] - indexVec[0] * (vecSize-1);
            for(int i = 1;i < vecSize;i++)
            {
                ret[indexVec[i]] = pre[vecSize-1]-pre[i] - indexVec[i]*(vecSize-1-i) + i*indexVec[i] - pre[i-1];//6-5*1+
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/intervals-between-identical-elements/description/