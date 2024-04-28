class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> numsStr(n);

        for(int i = 0;i < n;i++)
        {
            numsStr[i] = to_string(nums[i]);
        }
        sort(numsStr.begin(), numsStr.end(),[](const string& x,const string& y)
        {
            return x+y < y+x;
        });
        if(numsStr[n-1] == "0")
            return "0";
        string ret;
        for(int i = n-1;i >= 0;i--)
        {
            ret += numsStr[i];
        }
        return ret;
    }
};
//https://leetcode.cn/problems/largest-number/description/