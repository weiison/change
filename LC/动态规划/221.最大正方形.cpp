class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        if(cols==0) return 0;
        vector<vector<int>> dp(rows,vector<int>(cols,0));//i,j为右下角的最大矩形边长
        int maxLen=0;      
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(matrix[i][j]=='1')
                {
                    if(i-1>=0&&j-1>=0)
                    {
                        dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;//左，上，左上选一个最小的加1为当前最大
                    }
                    else dp[i][j]=1;
                }
                maxLen=max(dp[i][j],maxLen);
            }
        }
        return maxLen*maxLen;
    }
};
