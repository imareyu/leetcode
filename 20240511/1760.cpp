class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int n = nums.size();
        while(left <= right)
        {
            int mid = (right-left+1)/2+left;
            int index = upper_bound(nums.begin(), nums.end(), mid) - nums.begin();
            int opcount = 0;
            for(;index < n;index++)
            {
                opcount += (nums[index]+mid-1)/mid - 1;
            }
            //cout<<opcount<<" "<<mid<<endl;
            if(opcount > maxOperations)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return left;
    }
};
//https://leetcode.cn/problems/minimum-limit-of-balls-in-a-bag/