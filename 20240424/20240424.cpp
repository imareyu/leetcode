class Solution {
private:
    string pnum1;
    string pnum2;
    int n = 0;
    int pminsum = 0;
    int pmaxsum = 0;
private:
    long long dfs(int i,int sum, bool limitlow,bool limithigh,vector<vector<int>>& memory)
    {
        if(sum > pmaxsum)
        {
            return 0;
        }
        if(i == n)
        {
            return sum >= pminsum?1:0;
        }
        if(!limithigh&&!limitlow && memory[i][sum]!=-1)
        {
            return memory[i][sum];
        }
        int low = 0;
        if(limitlow)
        {
            low = pnum1[i]-'0';
        }
        int high = 9;
        if(limithigh)
        {
            high = pnum2[i]-'0';
        }
        long long ret = 0;
        for(int d= low;d <= high;d++)
        {
            ret = (ret+dfs(i+1, sum+d, limitlow&&d==low, limithigh&&d==high,memory))%(1000000007);
        }
        if(!limitlow&&!limithigh)
        {
            memory[i][sum] = ret;
        }
        return ret;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        n = num2.size();
        vector<vector<int>> memory(n, vector<int> (min(n*9,max_sum)+1, -1));
        pnum1 = string(n-num1.size(), '0') + num1;
        pnum2 = num2;
        pminsum = min_sum;
        pmaxsum = max_sum;
        return dfs(0,0,true,true,memory);
    }
};
//https://leetcode.cn/problems/count-of-integers/description/