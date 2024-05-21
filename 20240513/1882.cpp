class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> serverPq;//小顶堆 first是权重
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> taskPq;//first是下标
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> runningServer;//<结束时间，服务器下标>
        vector<int> ret(tasks.size(), 0);
        for(int i = 0;i < servers.size();i++)
        {
            serverPq.emplace(servers[i], i);
        }
        int minute = 0;
        int index = 0;
        while (true)
        {
            if(index >= tasks.size() && taskPq.empty())
            {
                break;
            }
            if(serverPq.empty())//没有服务器准备就绪，可以把minute调快
            {
                minute = runningServer.top().first;
            }
            //发现新的任务
            while(index <= minute && index < tasks.size())
            {
                taskPq.emplace(index, tasks[index]);
                index++;
            }
            //发现可以释放的服务器
            while(!runningServer.empty())
            {
                auto [endtime, idx] = runningServer.top();
                if(endtime <= minute)
                {
                    serverPq.emplace(servers[idx], idx);
                    runningServer.pop();
                }
                else
                {
                    break;
                }
            }
            //接下来给任务分配服务器
            while(!serverPq.empty() && !taskPq.empty())
            {//既有空闲服务器，又有需要分配的任务
                auto [serheavy, seridx] = serverPq.top();
                serverPq.pop();
                auto [taskidx, taskCostTime] = taskPq.top();
                taskPq.pop();
                runningServer.emplace(minute+taskCostTime, seridx);
                ret[taskidx] = seridx;                
            }
            minute++;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/process-tasks-using-servers/description/