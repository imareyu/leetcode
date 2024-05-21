class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> sta;
        vector<int> rightMinIndex(n, -1);//记录右边比自己小的数字的下标
        vector<int> leftMinIndex(n, -1);//记录左边边比自己小的数字的下标
        vector<long long> sums(n, 0);//包含自己的左侧和

        for(int i = 0;i < n;i++)
        {
            if(i == 0)
            {
                sums[i] = nums[i];
            }
            else
            {
                sums[i] = sums[i-1] + nums[i];
            }
            if(sta.empty())
            {
                sta.emplace(nums[i], i);
            }
            else
            {
                while(!sta.empty())
                {
                    if(sta.top().first <= nums[i])
                    {
                        break;
                    }
                    else
                    {
                        auto [val,index] = sta.top();
                        sta.pop();
                        rightMinIndex[index] = i;
                    }
                }
                sta.emplace(nums[i], i);
            }
        }

        for(int i = n-1;i >= 0;i--)
        {
            if(sta.empty())
            {
                sta.emplace(nums[i], i);
            }
            else
            {
                while(!sta.empty())
                {
                    if(sta.top().first <= nums[i])
                    {
                        break;
                    }
                    else
                    {
                        auto [val,index] = sta.top();
                        sta.pop();
                        leftMinIndex[index] = i;
                    }
                }
                sta.emplace(nums[i], i);
            }
        }

        long long ret = LLONG_MIN;
        //枚举最小值
        for(int i = 0;i < n;i++)
        {
            int left = leftMinIndex[i];
            int right = rightMinIndex[i];
            //cout<<left<<" "<<right<<endl;
            
            if(left == -1)
            {
                if(right == -1)
                {//左右全都比自己大
                    ret = max(ret, (long long)nums[i] * sums[n-1]);
                }
                else
                {
                    ret = max(ret, (long long)nums[i] * sums[right-1]);
                }
            }
            else
            {
                if(right == -1)
                {//
                    ret = max(ret, (long long)nums[i] * (sums[n-1] - sums[left]));
                }
                else
                {
                    ret = max(ret, (long long)nums[i] * (sums[right-1] - sums[left]));
                }
            }
        }
        long long mod = 1000000007;
        return ret%mod;
    }
};
//https://leetcode.cn/problems/maximum-subarray-min-product/