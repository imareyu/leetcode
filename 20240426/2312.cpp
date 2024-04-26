class Solution {
private:
    long long dfs(int x,int y,vector<vector<int>>& prices, vector<vector<int>>& memory,map<pair<int,int>, int>& data)
    {
        if(memory[x][y] != -1)
            return memory[x][y];
        long long maxret = 0;
        if(data.count(make_pair(x,y)) > 0)
            maxret = data[make_pair(x,y)];
        for(int i = 1;i < x;i++)
        {
            maxret = max(maxret, dfs(i,y,prices,memory,data) + dfs(x-i,y,prices,memory,data));
        }
        for(int i = 1;i < y;i++)
        {
            maxret = max(maxret, dfs(x,i,prices,memory,data) + dfs(x,y-i,prices,memory,data));
        }
        memory[x][y] = maxret;
        return maxret;
    }
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pair<int,int>, int> d;
        for(int i = 0;i < prices.size();i++)
        {
            d[make_pair(prices[i][0],prices[i][1])] = prices[i][2];
        }
        vector<vector<int>> memory(m+1, vector<int>(n+1, -1));
        return dfs(m, n, prices,memory,d);
    }
};
//https://leetcode.cn/problems/selling-pieces-of-wood/?envType=daily-question