class Solution {
private:
    vector<int> getNums(const string& num,const int& len1)
    {
        int retnum = 0;
        vector<int> ret;
        int i = 0;
        if(len1 == 0 || len1 == num.size())
        {
            for(;i < num.size();i++)
            {
                retnum = retnum*10 + (num[i]-'0');
            }
            ret.emplace_back(retnum);
            return ret;
        }
        for(;i < num.size()-len1;i++)
        {
            retnum = retnum*10 + (num[i]-'0');
        }
        ret.emplace_back(retnum);
        retnum = 0;
        for(;i < num.size();i++)
        {
            retnum = retnum*10 + (num[i]-'0');
        }
        ret.emplace_back(retnum);
        return ret;
    }
public:
    string minimizeResult(string expression) {
        int n = expression.size();
        string num1 = "";
        string num2 = "";
        bool first = true;

        for(int i = 0;i < n;i++)
        {
            if(expression[i] == '+')
            {
                first = false;
                continue;
            }
            if(first)
            {
                num1 += expression[i];
            }
            else
            {
                num2 += expression[i];
            }
        }
        int mn = stoi(num1) + stoi(num2);
        string mnStr = "("+ num1 + "+" + num2 + ")";
        
        for(int len1 = 1;len1 <= num1.size();len1++)//len1为靠近
        {
            for(int len2 = 0;len2 < num2.size();len2++)
            {
                vector<int> n12 = getNums(num1, len1);
                vector<int> n34 = getNums(num2, len2);
                int res = n12.back() + n34.front();
                if(n12.size() > 1)
                {
                    res *= n12[0];
                }
                if(n34.size() > 1)
                {
                    res *= n34[1];
                }
                if(res < mn)
                {
                    mn = res;
                    mnStr = num1.substr(0, num1.size()-len1)+"(" + num1.substr(num1.size()-len1 ,len1)+"+";
                    mnStr += num2.substr(0, num2.size()-len2)+")" + num2.substr(num2.size()-len2 ,len2);
                }
            }
        }
        return mnStr;
    }
};
//https://leetcode.cn/problems/minimize-result-by-adding-parentheses-to-expression/description/