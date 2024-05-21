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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> tree;
        int n = descriptions.size();
        unordered_map<int, bool> parents;

        for(int i = 0;i < n;i++)
        {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            bool isleftChild = (descriptions[i][2] == 1);
            if(tree.count(parent) == 0)
            {
                TreeNode* pnode = new TreeNode(parent);
                tree[parent] = pnode;
            }
            if(tree.count(child) == 0)
            {
                TreeNode* pnode = new TreeNode(child);
                tree[child] = pnode;
            }
            if(isleftChild)
            {
                tree[parent]->left = tree[child];
            }
            else
            {
                tree[parent]->right = tree[child];
            }
            if(parents.count(parent) == 0)//第一次出现
            {
                parents[parent] = true;
            }
            parents[child] = false;
        }
        int rootNum = 0;
        for(auto [val, b]:parents)
        {
            if(b)
            {
                rootNum = val;
                break;
            }
        }
        return tree[rootNum];
    }
};
//https://leetcode.cn/problems/create-binary-tree-from-descriptions/description/