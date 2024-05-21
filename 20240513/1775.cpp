class Solution {
private:
    int accumulateOp(vector<int>& nums1, vector<int>& nums2, int diff)
    {
        priority_queue<int, vector<int>, greater<int>> pq1(nums1.begin(), nums1.end());
        priority_queue<int, vector<int>, less<int>> pq2(nums2.begin(), nums2.end());//大顶堆
        int ret = 0;

        while(!pq1.empty() || !pq2.empty())
        {
            int change1 = 0;
            int change2 = 0;
            if(!pq1.empty())
            {
                change1 = 6 - pq1.top();
            }
            if(!pq2.empty())
            {
                change2 = pq2.top()-1;
            }
            if(change1 == 0 && change2 == 0)
                break;
            if(change1 > change2)
            {//
                if(change1 >= diff)
                {
                    ret++;
                    diff = 0;
                    break;
                }
                else
                {
                    diff -= change1;
                    ret++;
                    pq1.pop();
                }
            }
            else
            {
                if(change2 >= diff)
                {
                    ret++;
                    diff = 0;
                    break;
                }
                else
                {
                    diff -= change2;
                    ret++;
                    pq2.pop();
                }
            }
        }
        if(diff > 0)
            return -1;
        return ret;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        if(sum1 == sum2)
        {
            return 0;
        }
        int ret = 0;
        if(sum1 < sum2)
        {
            ret = accumulateOp(nums1, nums2, sum2 - sum1);
        }
        else
        {
            ret = accumulateOp(nums2, nums1, sum1 - sum2);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/equal-sum-arrays-with-minimum-number-of-operations/