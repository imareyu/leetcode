class Solution {
private:
    string toString4(int num)
    {
        if(num >= 1000)
            return to_string(num);
        if(num >= 100 && num <= 999)
            return "0" + to_string(num);
        if(num >= 10 && num <= 99)
            return "00" + to_string(num);
        return  "000" + to_string(num);
    }
public:
    string rankTeams(vector<string>& votes) {
        string ret;
        int m = votes.size();
        int n = votes[0].size();
        vector<int> ky(26, 0);
        vector<vector<int>> xs(26, vector<int>(26,0));//xs[i][j]表示i队伍排名第J获得了xs[i][j]票
        for(int j = 0;j < n;j++)
        {
            ky[votes[0][j]-'A'] = 1;
        }
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                char ch = votes[i][j];
                int x = ch - 'A';//x队伍
                xs[x][j]++;
            }
        }
        struct cmp
        {
            bool operator() (const pair<string,int>& a, const pair<string,int>& b)
            {
                if(a.first == b.first)
                {
                    return a.second > b.second;
                }
                return a.first < b.first;
            }
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>, cmp> pq;
        for(int i = 0;i < 26;i++)
        {//i队伍
            string str;
            for(int j = 0;j < 26;j++)//j排名
            {//排名有xs[i][j]次
                int count = xs[i][j];
                str += toString4(count);
            }
            pq.push(make_pair(str, i));
        }
        while(!pq.empty())
        {
            auto [str,index] = pq.top();
            //cout<<str<<"       "<<index<<endl;
            if(ky[index] == 1)
            {
                ret += (char)(index+'A');
            }
            pq.pop();
        }
        return ret;
    }
};
//https://leetcode.cn/problems/rank-teams-by-votes/