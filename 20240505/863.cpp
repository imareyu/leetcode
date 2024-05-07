/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(unordered_map<int,vector<int>>& tree,TreeNode* node)
    {
        if(!node)
            return ;

        if(node->left)
        {
            tree[node->val].push_back(node->left->val);
            tree[node->left->val].push_back(node->val);
            dfs(tree, node->left);
        }
        if(node->right)
        {
            tree[node->val].push_back(node->right->val);
            tree[node->right->val].push_back(node->val);
            dfs(tree, node->right);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0)
            return {target->val};
        unordered_map<int,vector<int>> tree;
        dfs(tree,root);

        vector<int> outcome;
        outcome.push_back(target->val);
        int index = 0;
        vector<int> addnode;

        for(int i = 0;i < k;i++)
        {
            addnode.clear();
            while(index < outcome.size())
            {
                int no = outcome[index];
                for(int nextno:tree[no])
                {
                    if(find(addnode.begin(), addnode.end(), nextno) == addnode.end() && find(outcome.begin(), outcome.end(), nextno) == outcome.end())
                    {
                        addnode.emplace_back(nextno);
                    }
                }
                index++;
            }
            outcome.insert(outcome.end(), addnode.begin(), addnode.end());
            if(addnode.size() == 0)
                break;
        }
        return addnode;
    }
};
//https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/