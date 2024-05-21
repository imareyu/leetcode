class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= n-1)//有5辆车，那么时间不管多快，必定在4小时以上
        {
            return -1;
        }
        int mx = *max_element(dist.begin(), dist.end());

        long long left = 1;
        long long right = mx*100;
        while(left <= right)
        {
            long long mid = (right-left+1) / 2 + left;
            long long costTime = 0;
            for(int i = 0;i < n-1;i++)
            {
                costTime += (dist[i] + mid - 1) / mid;//向上取整
            }
            double costTimedou = costTime;
            costTimedou += (double)dist[n-1] / (double)mid;
            if(costTimedou <= hour)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return left;
    }
};
//https://leetcode.cn/problems/minimum-speed-to-arrive-on-time/description/