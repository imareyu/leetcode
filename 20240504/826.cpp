class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> workDp;
        map<int, int> workDpMax;//难度对应的最大收益
        int n = difficulty.size();

        for(int i = 0;i < n;i++)
        {
            workDp.emplace_back(difficulty[i], profit[i]);
            if(workDpMax.count(difficulty[i]) > 0)
            {
                workDpMax[difficulty[i]] = max(workDpMax[difficulty[i]], profit[i]);
            }
            else
            {
                workDpMax[difficulty[i]] = profit[i];
            }
        }
        sort(workDp.begin(), workDp.end());
        
        int ret = 0;
        for(int i = 0;i < worker.size();i++)
        {
            int index = lower_bound(workDp.begin(), workDp.end(), make_pair(worker[i], -1))-workDp.begin();
            if(index == workDp.size())
            {
                index--;
            }
            if(workDp[index].first <= worker[i])
            {
                int di = workDp[index].first;
                int mx = -1;
                for(auto it = workDpMax.begin();it != workDpMax.end()&& it->first <= di;it++)
                {
                    mx = max(mx, it->second);
                }
                ret += mx;
            }
            else
            {
                index--;
                if(index >= 0&&workDp[index].first <= worker[i])
                {
                    int di = workDp[index].first;
                    int mx = -1;
                    for(auto it = workDpMax.begin();it != workDpMax.end()&&it->first <= di;it++)
                    {
                        mx = max(mx, it->second);
                    }
                    ret += mx;
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/most-profit-assigning-work/