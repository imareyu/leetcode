/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        if(!root)
            return "N";
        string strLeft = serialize(root->left);
        string strRight = serialize(root->right);
        str = to_string(root->val)+ " " + strLeft + " "+ strRight;
        return str;
    }
    TreeNode* dese(vector<string>& data,int& i)
    {
        if(data[i] == "N")
        {
            //i++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(atoi(data[i].c_str()));
        i++;
        root->left = dese(data, i);
        i++;
        root->right = dese(data, i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> t;
        int index = 0;
        string str = "";
        while(index < data.size())
        {
            if(data[index] != ' ')
            {
                str += data[index];
            }
            else
            {
                t.emplace_back(str);
                str = "";
            }
            index++;
        }
        t.emplace_back(str);
        int i = 0;
        return dese(t, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
//https://leetcode.cn/problems/serialize-and-deserialize-bst/description/