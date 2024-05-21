class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> diff(n+1, 0);

        for(int i = 0;i < requests.size();i++)
        {
            diff[requests[i][0]]++;
            diff[requests[i][1]+1]--;
        }

        vector<int> count;
        for(int i = 0;i < n;i++)
        {
            diff[i+1] += diff[i];
            if(diff[i])
            {
                count.emplace_back(diff[i]);
                //cout<<diff[i]<<endl;
            }
        }
        sort(count.begin(), count.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
        for(int i = 0;i < n;i++)
        {
            pq.emplace(nums[i], i);
        }
        long long ret = 0;
        for(int i = count.size()-1;i >= 0;i--)
        {
            auto [val, index] = pq.top();
            pq.pop();
            ret =(ret+ (long long)val * count[i])%1000000007;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/maximum-sum-obtained-of-any-permutation/