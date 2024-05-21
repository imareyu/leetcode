class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        map<int, int> count;

        for(int i = 0;i < n;i++)
        {
            if(wall[i].size() == 1)
            {
                continue;
            }
            int presum = wall[i][0];
            count[presum]++;
            for(int j = 1;j < wall[i].size()-1;j++)
            {
                presum += wall[i][j];
                count[presum]++;
            }
        }
        if(count.empty())
        {
            return n;
        }
        int val = count.begin()->first;
        int co = count.begin()->second;
        for(auto [v,c]: count)
        {
            if(c > co)
            {
                co = c;
                val = v;
            }
        }
        return n-  co;
    }
};
//https://leetcode.cn/problems/brick-wall/