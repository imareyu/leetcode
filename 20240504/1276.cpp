class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int toSlices = tomatoSlices;
        if(tomatoSlices%2 == 1)
            return {};

        int mincount = toSlices/4 + (toSlices%4)/2;
        int maxcount = toSlices/2;
        if(cheeseSlices < mincount || cheeseSlices > maxcount)
            return {};
        if(cheeseSlices == mincount)
        {
            return {toSlices/4, (toSlices%4)/2};
        }
        if(cheeseSlices == maxcount)
        {
            return {0, maxcount};
        }
        int ju = toSlices/4 - cheeseSlices+mincount;
        int xiao = (toSlices%4)/2+(cheeseSlices-mincount)*2;
        return {ju,xiao};
    }
};
//https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/description/