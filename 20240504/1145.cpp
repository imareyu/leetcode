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
    TreeNode* findNode(TreeNode* root,int x)
    {
        if(root->val == x)
            return root;
        TreeNode* ret = nullptr;
        if(root->left)
            ret = findNode(root->left, x);
        if(ret)
            return ret;
        if(root->right)
            ret = findNode(root->right, x);
        return ret;
    }
    int countNode(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        int cl = countNode(root->left);
        int cr = countNode(root->right);
        return cl + cr + 1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* nodex = findNode(root, x);
        int nodexLeft = countNode(nodex->left);
        int nodexRight = countNode(nodex->right);
        int mx = max(nodexLeft, nodexRight);
        mx = max(mx, n-nodexLeft-nodexRight-1);
        if(mx > n-mx)
            return true;
        return false;
    }
};
//https://leetcode.cn/problems/binary-tree-coloring-game/description/