/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    string findsmall(string str1,string str2)
    {
        if(str1 == str2)
            return str1;
        int minSize = str1.size() < str2.size()?str1.size():str2.size();
        int i = 0;
        for(;i < minSize;i++)
        {
            if(str1[i] != str2[i])
            {
                break;
            }
        }
        if(i == minSize)
        {
            return str1.size() < str2.size()?str1:str2;
        }
        return str1[i]<str2[i]? str1:str2;
    }
    void dfs(string str,TreeNode* root, string& ret)
    {
        if(!root->left && !root->right)
        {
            str = (char)(root->val+'a') + str;
            if(ret.size() == 0)
            {
                ret = str;
            }
            else
            {
                ret = findsmall(ret, str);
            }
            return ;
        }
        if(root->left)
        {
            dfs((char)(root->val+'a')+str, root->left, ret);
        }
        if(root->right)
        {
            dfs((char)(root->val+'a')+str, root->right, ret);
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ret;
        dfs("", root, ret);
        return ret;
    }
};
//https://leetcode.cn/problems/smallest-string-starting-from-leaf/description/