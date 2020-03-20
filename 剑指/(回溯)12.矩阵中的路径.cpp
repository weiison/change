class Solution {
public:
    bool existCore(vector<vector<char>>& board,int row,int col,int rows,int cols,string& word,int& now,vector<vector<int>>& vis)                         
    {
        if(now==word.size()) return true;//扫描到尾部则找到
        bool flag=false;
        if(row>=0&&row<rows&&col>=0&&col<cols&&board[row][col]==word[now]&&vis[row][col]==0)
        {
            ++now;
            vis[row][col]=1;
            flag=existCore(board,row+1,col,rows,cols,word,now,vis)||
                existCore(board,row-1,col,rows,cols,word,now,vis)||
                existCore(board,row,col-1,rows,cols,word,now,vis)||
                existCore(board,row,col+1,rows,cols,word,now,vis);
            if(!flag)
            {
                --now;//若不是& 则可以删去此行
                vis[row][col]=0;
            }
        }
        return flag;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<int>> vis(rows,vector<int>(cols,0));
        int now=0; 
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(existCore(board,i,j,rows,cols,word,now,vis))
                    return true;
            }
        }
        return false;
    }
};
