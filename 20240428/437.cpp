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
    int ret = 0;
    void dfs(TreeNode* node, int target,vector<long long> sums)
    {
        if(!node)
        {
            return ;
        }
        vector<long long> newsums;
        for(int i = 0;i < sums.size();i++)
        {
            long long temp = sums[i] + node->val;
            if(temp == target)
            {
                ret++;
            }
            newsums.push_back(temp);
        }
        if(node->val == target)
        {
            ret++;
        }
        newsums.push_back(node->val);
        dfs(node->left, target, newsums);
        dfs(node->right, target, newsums);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
        {
            return 0;
        }
        ret = 0;
        vector<long long> sums;
        dfs(root,targetSum, sums);
        return ret;
    }
};
//https://leetcode.cn/problems/path-sum-iii/