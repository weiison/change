//不关心路径是怎么走，只关心有多长，使用动态规划减少重复问题的计算
class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp)
    {
        if(dp[i][j]!=0) return dp[i][j];
        //从四个方向中选一个最大的
        if(i+1<matrix.size()&&matrix[i+1][j]>matrix[i][j]) 
            dp[i][j]=max(dp[i][j],dfs(matrix,i+1,j,dp));
        if(i-1>=0&&matrix[i-1][j]>matrix[i][j]) 
            dp[i][j]=max(dp[i][j],dfs(matrix,i-1,j,dp));
        if(j+1<matrix[0].size()&&matrix[i][j+1]>matrix[i][j]) 
            dp[i][j]=max(dp[i][j],dfs(matrix,i,j+1,dp));
        if(j-1>=0&&matrix[i][j-1]>matrix[i][j]) 
            dp[i][j]=max(dp[i][j],dfs(matrix,i,j-1,dp));
        return ++dp[i][j];//加上当前位置                                    
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        if(rows==0) return 0;
        int cols=matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));//以当前位置为起点的递增路径最长长度
        int res=0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                res=max(res,dfs(matrix,i,j,dp));
            }
        }
        return res;
    }
};
