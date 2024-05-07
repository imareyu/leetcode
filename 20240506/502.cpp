class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> data;
        int n = profits.size();
        int mnCap = capital[0];

        for(int i = 0;i < n;i++)
        {
            data.emplace_back(capital[i], profits[i]);
            mnCap = min(mnCap, capital[i]);
        }
        if(mnCap > w)//无法达到启动的要求，直接0
        {
            return 0;
        }
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first == b.first)
            {
                return a.second < b.second;
            }
            return a.first < b.first;
        };
        sort(data.begin(), data.end(), cmp);
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        //大顶堆，first是profit,second是capital
        int wei = w;
        int count = 0;
        int index = 0;
        while(count < k)
        {
            while(index < n && data[index].first <= wei)
            {
                pq.push(make_pair(data[index].second, data[index].first));
                index++;
            }
            if(pq.empty())
                break;
            auto [pro, cap] = pq.top();
            pq.pop();
            wei += pro;
            count++;
        }
        return wei;
    }
};
//https://leetcode.cn/problems/ipo/