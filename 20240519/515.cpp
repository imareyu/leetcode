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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        deque<TreeNode*> dq;
        dq.emplace_back(root);
        vector<int> ret;

        while(!dq.empty())
        {
            int dqSize = dq.size();
            int mx = dq.front()->val;
            while(dqSize > 0)
            {
                auto it = dq.front();
                dq.pop_front();
                mx = max(mx, it->val);
                if(it->left)
                {
                    dq.emplace_back(it->left);
                }
                if(it->right)
                {
                    dq.emplace_back(it->right);
                }
                dqSize--;
            }
            ret.emplace_back(mx);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/find-largest-value-in-each-tree-row/