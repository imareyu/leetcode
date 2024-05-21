class Solution {
private:
    bool checkrow(vector<vector<char>>& board, int row, int start,int end, string word)
    {
        //正序
        int dis = 0;
        for(;dis < word.size();dis++)
        {
            if(board[row][start+dis] == ' ' || board[row][start+dis] == word[dis])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(dis >= word.size())
        {
            return true;
        }
        //反序
        dis = 0;
        for(;dis < word.size();dis++)
        {
            if(board[row][end-1-dis] == ' ' || board[row][end-1-dis] == word[dis])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(dis >= word.size())
        {
            return true;
        }
        return false;
    }
    bool checkcol(vector<vector<char>>& board, int col, int start,int end, string word)
    {
        cout<<"col"<<col<<start<<end<<endl;
        //正序
        int dis = 0;
        for(;dis < word.size();dis++)
        {
            if(board[start+dis][col] == ' ' || board[start+dis][col] == word[dis])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(dis >= word.size())
        {
            return true;
        }
        //反序
        dis = 0;
        for(;dis < word.size();dis++)
        {
            if(board[end-1-dis][col] == ' ' || board[end-1-dis][col] == word[dis])
            {
                continue;
            }
            else
            {
                break;
            }
        }
        if(dis >= word.size())
        {
            return true;
        }
        return false;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        int wordSize = word.size();

        for(int i = 0;i < m;i++)
        {
            int start = 0;
            int j = 0;
            for(;j < n;j++)
            {
                if(board[i][j] == '#')//出现了一个#标识，说明之前的结束了
                {
                    if(start == j)
                    {
                        start = j+1;
                        continue;
                    }
                    else
                    {
                        if(j - start == wordSize)
                        {
                            if(checkrow(board, i, start, j, word))//检查i行从start到j-1是否可以把word放进去
                            {
                                return true;
                            }
                        }
                        start = j+1;
                    }
                }
            }
            if(j - start == wordSize)
            {
                if(checkrow(board, i, start, j, word))//检查i行从start到j-1是否可以把word放进去
                {
                    return true;
                }
            }
        }
        for(int j = 0;j < n;j++)
        {
            int start = 0;
            int i = 0;
            for(;i < m;i++)
            {
                if(board[i][j] == '#')//出现了一个#标识，说明之前的结束了
                {
                    if(start == i)
                    {
                        start = i+1;
                        continue;
                    }
                    else
                    {
                        if(i - start == wordSize)
                        {
                            if(checkcol(board, j, start, i, word))//检查i行从start到j-1是否可以把word放进去
                            {
                                return true;
                            }
                        }
                        start = i+1;
                    }
                }
            }
            if(i - start == wordSize)
            {
                if(checkcol(board, j, start, i, word))//检查i行从start到j-1是否可以把word放进去
                {
                    return true;
                }
            }
        }
        return false;
    }
};
//https://leetcode.cn/problems/check-if-word-can-be-placed-in-crossword/