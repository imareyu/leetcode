/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* constructBack(vector<vector<int>>& grid, int x,int y,int n)
    {
        int sum = 0;
        Node* no = new Node();
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                sum += grid[x+i][y+j];
            }
        }
        if(sum == 0 || sum == n*n)
        {//相同
            no->isLeaf = true;
            no->val = sum;
        }
        else
        {
            no->topLeft = constructBack(grid,x,y,n/2);
            no->topRight = constructBack(grid,x,y+n/2,n/2);
            no->bottomLeft = constructBack(grid,x+n/2,y,n/2);
            no->bottomRight = constructBack(grid,x+n/2,y+n/2,n/2);
        }
        return no;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructBack(grid, 0, 0, n);
    }
};
//https://leetcode.cn/problems/construct-quad-tree/