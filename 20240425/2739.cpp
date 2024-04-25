class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ret = 0;
        while(mainTank >= 5 && additionalTank > 0)
        {
                int c = mainTank / 5;
                ret += c * 50;
                mainTank = mainTank%5;
                mainTank += min(c, additionalTank);
                additionalTank -= min(c, additionalTank);
        }
        if(mainTank)
        {
            ret += 10 * mainTank;
        }
        return ret;
    }
};
//https://leetcode.cn/problems/total-distance-traveled/?envType=daily-question