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
    int maxcount = 0;
    int dfs(TreeNode* node, map<int,int>& count)
    {
        if(!node)
        {
            return 0;
        }
        int leftSum = 0;
        int rightSum = 0;
        if(node->left)
        {
            leftSum = dfs(node->left, count);
        }
        if(node->right)
        {
            rightSum = dfs(node->right, count);
        }
        int sum = node->val+leftSum+rightSum;
        count[sum]++;
        maxcount = max(maxcount, count[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxcount = 0;
        map<int, int> count;
        dfs(root, count);
        vector<int> ret;
        for(auto [num,co]:count)
        {
            if(co == maxcount)
            {
                ret.push_back(num);
            }
        }
        return ret;
    }
};
//https://leetcode.cn/problems/most-frequent-subtree-sum/