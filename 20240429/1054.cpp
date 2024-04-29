class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> data;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;

        for(int i = 0;i < barcodes.size();i++)
        {
            data[barcodes[i]]++;
        }
        for(auto [val, count]:data)
        {
            pq.push(make_pair(count, val));
        }
        vector<int> ret;
        while(!pq.empty())
        {
            auto [count1, val1] = pq.top();
            //cout<<count1<<"=======1111====="<<val1<<endl;
            pq.pop();
            if(!pq.empty())
            {
                auto [count2, val2] = pq.top();
                pq.pop();
                //cout<<count2<<"=======2222====="<<val2<<endl;
                if(ret.size() > 0)
                {
                    if(ret.back() == val1)
                    {
                        pq.push(make_pair(count1, val1));
                        ret.push_back(val2);
                        count2--;
                        if(count2)
                            pq.push(make_pair(count2, val2));
                    }
                    else
                    {
                        pq.push(make_pair(count2, val2));
                        ret.push_back(val1);
                        count1--;
                        if(count1)
                            pq.push(make_pair(count1, val1));
                    }
                }
                else
                {
                    pq.push(make_pair(count2, val2));
                    ret.push_back(val1);
                    count1--;
                    if(count1)
                        pq.push(make_pair(count1, val1));
                }
            }
            else
                ret.push_back(val1);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/distant-barcodes/description/