class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int mx = *max_element(costs.begin(), costs.end());
        vector<int> count(mx+1, 0);

        for(int num:costs)
        {
            count[num]++;
        }
        int i = 0;
        int ret = 0;
        while(i <= mx && coins > 0)
        {
            if(count[i] > 0)
            {
                if(count[i] <= coins/i)
                {
                    ret += count[i];
                    coins -= i*count[i];
                }
                else
                {
                    int co = coins/i;
                    ret += co;
                    break;
                }
            }
            i++;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/maximum-ice-cream-bars/