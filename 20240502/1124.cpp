class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> data(n+1, 0);

        for(int i = 0;i < n;i++)
        {
            if(hours[i] > 8)
            {
                data[i+1] = data[i]+1;
            }
            else
            {
                data[i+1] = data[i]-1;
            }
        }

        int ret = 0;
        for(int i = 0;i <= n;i++)
        {
            for(int j = n;j > i;j--)
            {
                if(data[j] - data[i] > 0)
                {
                    ret = max(ret, j-i);
                    break;
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/longest-well-performing-interval/description/