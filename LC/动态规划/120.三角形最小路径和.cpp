class Solution {
public:
    //递归求解 会有重复计算
    int minimumTotal(vector<vector<int>>& triangle,int i,int j)
    {
        if(i==triangle.size()) return 0;
        int one=minimumTotal(triangle,i+1,j);
        int two=minimumTotal(triangle,i+1,j+1);
        return min(one,two)+triangle[i][j];

    }
    //自底向上推，结果保存，避免重复计算
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0) return 0;
        int row=triangle.size();
        int col=triangle[row-1].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int j=0;j<col;++j)
            dp[row-1][j]=triangle[row-1][j];
        for(int i=row-2;i>=0;--i)
        {
            for(int j=0;j<triangle[i].size();++j)
            {
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
