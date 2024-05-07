class Solution {
public:
    int mirrorReflection(int p, int q) {
        int len = p;
        int x = p;
        int y = q;
        while(true)
        {
            if(x%len == 0 && y%len == 0)
            {
                break;
            }
            x += p;
            y += q;
        }
        if((x/len)%2 == 0)
        {
            return 2;
        }
        else
        {
            if((y/len)%2 == 0)
            {
                return 0;
            }
        }
        return 1;
    }
};
//https://leetcode.cn/problems/mirror-reflection/