class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret(n);
        struct cmp
        {
            bool operator()(const pair<int,int> &a,const pair<int,int> &b)
            {
                if(a.first == b.first)
                {
                    return a.second > b.second;
                }
                return a.first < b.first;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;//大顶堆
        sort(nums.begin(), nums.end());
        
        ret[0].push_back(nums[0]);
        pq.push(make_pair(1,0));
        int maxlen = 1;
        int maxlenIndex = 0;
        for(int i = 1;i < n;i++)
        {
            vector<pair<int,int>> pushdata;
            while(!pq.empty())
            {
                auto [len,index] = pq.top();
                if(nums[i]%nums[index] == 0 || nums[index]%nums[i] == 0)
                {
                    break;
                }
                pushdata.emplace_back(len, index);
                pq.pop();
            }
            if(pq.empty())//没有可以整除的，就放一个当前的元素
            {
                ret[i].push_back(nums[i]);
                pq.push(make_pair(1, i));
            }
            else
            {
                //cout<<"i="<<i<<endl;
                auto [len,index] = pq.top();
                ret[i] = ret[index];
                //cout<<"lenindex = "<<len<<" "<<index<<endl;
                //for(auto aa:ret[i])
                //    cout<<aa<<" ";
                //cout<<endl;
                ret[i].push_back(nums[i]);
                pq.push(make_pair(len+1,i));
                if(len+1 > maxlen)
                {
                    maxlen = len + 1;
                    maxlenIndex = i;
                }
            }
            for(auto p:pushdata)
            {
                pq.push(p);
            }
        }
        return ret[maxlenIndex];
    }
};
//https://leetcode.cn/problems/largest-divisible-subset/description/