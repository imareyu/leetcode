class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int> losers;
        unordered_set<int> players;
        vector<vector<int>> ret(2);

        for(int i = 0;i < n;i++)
        {
            int winner = matches[i][0];
            int loser = matches[i][1];
            losers[loser]++;
            players.insert(winner);
            players.insert(loser);
        }

        for(int player:players)
        {
            if(losers.count(player) == 0)
            {
                ret[0].emplace_back(player);
            }
            else
            {
                if(losers[player] == 1)
                {
                    ret[1].emplace_back(player);
                }
            }
        }
        sort(ret[0].begin(), ret[0].end());
        sort(ret[1].begin(), ret[1].end());
        return ret;
    }
};
//https://leetcode.cn/problems/find-players-with-zero-or-one-losses/description/