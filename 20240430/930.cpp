class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> index1;//数字1的下标

        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 1)
            {
                index1.emplace_back(i);
            }
        }
        if(index1.size() < goal)
            return 0;
        if(goal == 0)
        {
            if(index1.size() == 0)
                return n*(n+1)/2;
            int ret = 0;
            ret += index1[0]*(index1[0]+1)/2;
            for(int i = 1;i < index1.size();i++)
            {
                ret += (index1[i]-index1[i-1]-1)*(index1[i]-index1[i-1])/2;
            }
            ret += (n-index1.back()-1)*(n-index1.back())/2;
            return ret;
        }
        int ret = 0;
        for(int i = 0;i < index1.size()-goal+1;i++)
        {
            cout<<"i = "<<i<<endl;
            int left = index1[i];
            int right = index1[i+goal-1];
            cout<<"left = "<<left<<endl;
            cout<<"right = "<<right<<endl;
            int countleft0 = 0;
            if(i > 0)
            {
                countleft0 = index1[i] - index1[i-1]-1;
            }
            else
            {
                countleft0 = index1[i];
            }
            int countright0 = 0;
            if(i+goal < index1.size())
            {
                countright0 = index1[i+goal] - index1[i+goal-1]-1;
            }
            else
            {
                countright0 = n - index1[i+goal-1]-1;
            }
            ret += (countleft0 + 1) * (countright0 + 1);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/binary-subarrays-with-sum/description/