//在一个矩阵中搜索是否包含一组单词中的某几个
class TrieNode{
public:
    string word;
    vector<TrieNode*> nodes;
    TrieNode():nodes(26, nullptr),word(""){}
};

class Solution {
    int rows,cols;
    vector<string> res;
public:
    void dfs(vector<vector<char>>& board,TrieNode* root,int i,int j)
    {
        char c=board[i][j];
        if(c=='.'||root->nodes[c-'a']==nullptr) return;//已经走过或者不包含在前缀树内
        root=root->nodes[c-'a'];
        if(root->word!="")
        {
            res.push_back(root->word);
            root->word="";
        }
        board[i][j]='.';//避免重复使用
        if(i>0) dfs(board,root,i-1,j);
        if(i+1<rows) dfs(board,root,i+1,j);
        if(j>0) dfs(board,root,i,j-1);
        if(j+1<cols) dfs(board,root,i,j+1);
        board[i][j]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows=board.size();
        if(rows==0) return res;
        cols=board[0].size();
        if(cols==0) return res;

        TrieNode* root=new TrieNode();
        for(auto word:words)
        {
            TrieNode* now=root;
            for(int i=0;i<word.size();++i)
            {
                int idx=word[i]-'a';
                if(now->nodes[idx]==nullptr) now->nodes[idx]=new TrieNode();
                now=now->nodes[idx];
            }
            now->word=word;
        }

        for(int i=0;i<rows;++i)
            for(int j=0;j<cols;++j)
                dfs(board,root,i,j);
        
        return res;
    }
};
