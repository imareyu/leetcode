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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> dq;
        vector<vector<int>> ret;
        bool zh = true;

        if(root)
            dq.push_back(root);
        while(!dq.empty())
        {
            int dqSize = dq.size();
            vector<int> tempdata;
            while(dqSize > 0)
            {
                auto it = dq.front();
                dq.pop_front();
                tempdata.push_back(it->val);
                if(it->left)
                {
                    dq.push_back(it->left);
                }
                if(it->right)
                {
                    dq.push_back(it->right);
                }
                dqSize--;
            }
            if(!zh)
            {
                reverse(tempdata.begin(), tempdata.end());
            }
            zh = !zh;
            ret.emplace_back(tempdata);
        }
        return ret;
    }
};
//https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/