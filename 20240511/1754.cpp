class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ret = "";
        int len = word1.size() + word2.size();
        int i1 = 0;
        int i2 = 0;

        while(ret.size() < len)
        {
            if(word1[i1] > word2[i2])
            {
                ret += word1[i1];
                i1++;
            }
            else
            {
                if(word1[i1] < word2[i2])
                {
                    ret += word2[i2];
                    i2++;
                }
                else
                {
                    bool chooseFirst = false;
                    for(int j = 0;;j++)
                    {
                        if(i1+j >= word1.size())
                        {
                            chooseFirst = false;
                            break;
                        }
                        if(i2+j >= word2.size())
                        {
                            chooseFirst = true;
                            break;
                        }
                        if(word1[i1+j] > word2[i2+j])
                        {
                            chooseFirst = true;
                            break;
                        }
                        else
                        {
                            if(word1[i1+j] < word2[i2+j])
                            {
                                chooseFirst =false;
                                break;
                            }
                        }
                    }
                    if(chooseFirst)
                    {
                        ret += word1[i1];
                        i1++;
                    }
                    else
                    {
                        ret += word2[i2];
                        i2++;
                    }
                }
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/largest-merge-of-two-strings/