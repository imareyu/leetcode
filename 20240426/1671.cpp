class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;//大顶堆
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        dp1[0] = 1;
        pq.push(make_pair(dp1[0], 0));

        for(int i = 1;i < n;i++)
        {
            vector<pair<int,int>> tempdata;
            while(!pq.empty())
            {
                auto [d, index] = pq.top();
                //if(i == 15)
                //{
                //    cout<<"15========"<<d<<"  "<<index<<endl;
                //}
                if(nums[index] < nums[i])
                {
                    dp1[i] = d+1;
                    tempdata.emplace_back(dp1[i], i);
                    break;
                }
                else
                {
                    tempdata.emplace_back(d,index);
                    pq.pop();
                }
            }
            if(pq.empty())
            {
                pq.push(make_pair(1,i));
                dp1[i] = 1;
            }
            for(auto [d,index]: tempdata)
            {
                pq.push(make_pair(d,index));
            }
            //cout<<dp1[i]<<" ";
        }
        //cout<<endl;
        while(!pq.empty())
            pq.pop();
        
        dp2[n-1] = 1;
        pq.push(make_pair(1, n-1));
        for(int i = n-2;i >= 0;i--)
        {
            vector<pair<int,int>> tempdata;
            while(!pq.empty())
            {
                auto [d, index] = pq.top();
                if(nums[index] < nums[i])
                {
                    dp2[i] = d+1;
                    tempdata.emplace_back(dp2[i], i);
                    break;
                }
                else
                {
                    tempdata.emplace_back(d,index);
                    pq.pop();
                }
            }
            if(pq.empty())
            {
                pq.push(make_pair(1,i));
                dp2[i] = 1;
            }
            for(auto [d,index]: tempdata)
            {
                pq.push(make_pair(d,index));
            }
            //cout<<dp2[i]<<" ";
        }
        int ret = 0;
        for(int i = 0;i < n;i++)
        {
            if(dp1[i] > 1 && dp2[i] > 1)
            {
                if(dp1[i]+dp2[i]-1 > ret)
                {
                    ret = dp1[i]+dp2[i]-1;
                }
            }
        }
        return n-ret;
    }
};
//https://leetcode.cn/problems/minimum-number-of-removals-to-make-mountain-array/description/?envType=daily-question