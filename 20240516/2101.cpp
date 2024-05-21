class Solution {
#define ll long long
private:
    void bfs(unordered_set<int>& exploed, map<int,vector<int>> nextBomb)
    {
        unordered_set<int> bombs(exploed.begin(), exploed.end());
        while(!bombs.empty())
        {
            unordered_set<int> addBombs;
            for(int bomb:bombs)
            {
                for(int nb:nextBomb[bomb])
                {
                    if(exploed.count(nb) == 0)
                    {
                        exploed.insert(nb);
                        addBombs.insert(nb);
                    }
                }
            }
            bombs = move(addBombs);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        map<int,vector<int>> nextBomb;

        for(int i = 0;i < n;i++)
        {
            ll x = bombs[i][0];
            ll y = bombs[i][1];
            ll r = bombs[i][2];

            for(int j = i+1;j < n;j++)
            {
                if(j == i)
                {
                    continue;
                }
                ll x1 = bombs[j][0];
                ll y1 = bombs[j][1];
                ll r1 = bombs[j][2];
                ll dis2 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
                if(dis2 <= r*r)
                {
                    nextBomb[i].emplace_back(j);
                }
                if(dis2 <= r1*r1)
                {
                    nextBomb[j].emplace_back(i);
                }
            }
        }
        int ret  = 1;
        for(auto& [startBomb,nbs]:nextBomb)
        {
            unordered_set<int> exploed;
            exploed.insert(startBomb);
            bfs(exploed, nextBomb);
            ret = max(ret, (int)exploed.size());
        }
        return ret;
    }
};
//https://leetcode.cn/problems/detonate-the-maximum-bombs/description/