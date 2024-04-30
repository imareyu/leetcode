class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 1;
        int yu = num % k;
        unordered_set<int> used;
        used.insert(1);

        while(yu)
        {
            num = yu*10 + 1;
            yu = num % k;
            if(used.count(num) > 0)
                return -1;
            used.insert(num);
        }
        return used.size();
    }
};
//https://leetcode.cn/problems/smallest-integer-divisible-by-k/description/