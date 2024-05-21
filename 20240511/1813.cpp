class Solution {
private:
    bool check(vector<string>& word1,vector<string>& word2)
    {
        if(word1.size() == word2.size())
        {
            for(int i = 0;i < word1.size();i++)
            {
                if(word1[i] != word2[i])
                    return false;
            }
            return true;
        }
        //前缀判断
        int i = 0;
        int j = 0;
        for(;i < word1.size();i++)
        {
            if(word1[i] != word2[i])
            {
                break;
            }
        }
        if(i >= word1.size())
            return true;
        //后缀
        for(i = word1.size()-1,j = word2.size()-1;i >= 0;i--,j--)
        {
            if(word1[i] != word2[j])
            {
                break;
            }
        }
        if(i < 0)
            return true;

        //前后判断
        for(i = 0;i < word1.size();i++)
        {
            if(word1[i] != word2[i])
            {
                break;
            }
        }
        int k = word1.size()-1;
        for(j = word2.size()-1;k >= 0;k--,j--)
        {
            if(word1[k] != word2[j])
            {
                break;
            }
        }
        if(k <= i-1)
            return true;
        return false;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1 == sentence2)
            return true;
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        if(n1 == n2)
            return false;
        vector<string> word1;
        vector<string> word2;

        string str = "";
        for(int i = 0;i < n1;i++)
        {
            if(sentence1[i] == ' ')
            {
                word1.emplace_back(str);
                str = "";
            }
            else
            {
                str += sentence1[i];
            }
        }
        word1.emplace_back(str);
        str = "";
        for(int i = 0;i < n2;i++)
        {
            if(sentence2[i] == ' ')
            {
                word2.emplace_back(str);
                str = "";
            }
            else
            {
                str += sentence2[i];
            }
        }
        word2.emplace_back(str);

        //判断是否为前缀
        if(word1.size() < word2.size())
            return check(word1, word2);
        else
            return check(word2, word1);
        return false;
    }
};
//https://leetcode.cn/problems/sentence-similarity-iii/