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
    bool isCompleteTree(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool kong = false;

        while(!dq.empty())
        {
            //deque<TreeNode*> dq2;
            int dqsize = dq.size();
            bool nextkong = false;
            while(dqsize > 0)
            {
                TreeNode* it = dq.front();
                dq.pop_front();
                if(it->left && it->right)
                {
                    if(nextkong)
                        return false;
                    dq.push_back(it->left);
                    dq.push_back(it->right);
                }
                else
                {
                    if(it->right && !it->left)
                    {
                        return false;
                    }
                    else
                    {
                        if(it->left && !it->right)
                        {
                            if(nextkong)
                                return false;
                            nextkong = true;
                            dq.push_back(it->left);
                        }
                        else
                        {
                            nextkong = true;
                        }
                    }
                }
                dqsize--;
            }
            if(kong && !dq.empty())
                return false;
            kong = nextkong;
        }
        return true;
    }
};
//https://leetcode.cn/problems/check-completeness-of-a-binary-tree/