class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int num = target;
        int ret = 0;

        while(num > 1 && maxDoubles > 0)
        {
            if(num%2 == 1)
            {
                ret++;
                num--;
            }
            else
            {
                num /= 2;
                maxDoubles--;
                ret++;
            }
        }
        ret += num-1;
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-moves-to-reach-target-score/description/