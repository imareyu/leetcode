class Solution {
private:
    int m = 0;
    int n = 0;
    int maxret = 0;
    int dfs(vector<pair<int,int>>& road,vector<string>& data,map<string,int>& mapdata,string unsearch)
    {
        if(unsearch.size() == 0)
            return 0;
        if(mapdata.count(unsearch) > 0)
        {
            //cout<<unsearch<<"="<<mapdata[unsearch]<<endl;
            return mapdata[unsearch];
        }
        int ret = 0;
        int x = 0;
        int y = -1;
        if(!road.empty())
        {
            x = road[road.size()-1].first;
            y = road[road.size()-1].second;
        }
        int i = x;
        int j = 0;
        int c = 0;
        for(;i < m;i++)
        {
            if(i == x)
                j = y+1;
            else
                j = 0;
            for(;j < n;j++)
            {
                if(data[i][j] == '1')
                {
                    c=1;
                    road.push_back(make_pair(i, j));
                    //处理本行状态存储和修改
                    string nowline = data[i];
                    data[i][j] = '0';
                    if(j-1 >= 0)
                        data[i][j-1] = '0';
                    if(j+1 < n)
                        data[i][j+1] = '0';
                    
                    //处理下一行
                    string nextline = "";
                    if(i+1 < m)
                    {
                        nextline = data[i+1];
                        if(j-1 >= 0)
                            data[i+1][j-1] = '0';
                        if(j+1 < n)
                            data[i+1][j+1] = '0';
                    }
                    //记录未搜索的
                    string shengyu="";
                    int jj = 0;
                    for(int ii = i;ii < m;ii++)
                    {
                        if(ii == i)
                        {
                            jj = j+1;
                            for(;jj < n;jj++)
                            shengyu += data[ii][jj];
                        }
                        else
                        {
                            shengyu += data[ii];
                        }
                    }

                    int rettemp = dfs(road, data, mapdata,shengyu);

                    ret = max(rettemp, ret);
                    //cout<<"ret="<<ret<<endl;
                    if(mapdata.count(shengyu) == 0)
                        mapdata[shengyu] = rettemp;
                    //恢复状态
                    data[i] = nowline;
                    if(i+1 < m)
                        data[i+1] = nextline;
                    road.pop_back();
                }
            }
        }
        if(ret + c > maxret)
            maxret = ret + c;
        return ret + c;
    }
public:
    int maxStudents(vector<vector<char>>& seats) {//左右翻转不会影响结果
        m = seats.size();
        n = seats[0].size();
        vector<string> data(m);
        map<string,int> mapdata;
        string temp = "";

        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(seats[i][j] == '.')
                {
                    data[i].push_back('1');
                }
                else
                {
                    data[i].push_back('0');
                }
            }
            temp += data[i];
        }
        vector<pair<int,int>> road;

        dfs(road, data, mapdata, temp);
        return maxret;
    }
};
//https://leetcode.cn/problems/maximum-students-taking-exam/description/?envType=daily-question