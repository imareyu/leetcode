class Solution {
private:
    int ret = 0;
    void dfs(char ch,string& answerKey,int k)
    {
        int n = answerKey.size();
        int left = 0;
        int right = 0;
        int tk = k;

        while (left <= n - k)
        {
            while(right < n&& answerKey[right] == ch || tk > 0)//ch T
            {
                if(right >= n)
                {
                    break;
                }
                if(answerKey[right] != ch)
                {
                    tk--;
                }
                right++;
            }
            ret = max(ret, right-left);
            if(answerKey[left] != ch)
            {
                tk++;
            }
            left++;
        }
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        ret = 0;
        dfs('T', answerKey, k);
        dfs('F', answerKey, k);
        return ret;
    }
};
//https://leetcode.cn/problems/maximize-the-confusion-of-an-exam/description/