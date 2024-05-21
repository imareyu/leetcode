class Solution {
private:
    bool myNextPermutation(string& num)
    {
        int n = num.size();
        int i = n-2;

        while(i >= 0)
        {
            if(num[i] < num[i+1])
            {
                break;
            }
            i--;
        }
        if(i < 0)//降序排列
        {
            return false;
        }
        int j = n-1;
        while(num[j] <= num[i])
        {
            j--;
        }
        swap(num[i], num[j]);
        reverse(num.begin()+i+1, num.end());
        return true;
    }
public:
    int getMinSwaps(string num, int k) {
        int i = 0;
        string aimNum = num;
        int n = num.size();
        while(i < k)
        {
            myNextPermutation(aimNum);
            i++;
        }
        int ret = 0;
        for(int j = 0;j < n;j++)
        {
            if(aimNum[j] != num[j])
            {
                for(int k = j+1;k < n;k++)
                {
                    if(aimNum[j] == num[k])
                    {
                        for(int x = k;x > j;x--)
                        {
                            ret++;
                            swap(num[x], num[x-1]);
                        }
                        break;
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/