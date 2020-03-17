//dp[n]表示长度为n绳子最大乘积,可以不切，题目要求至少切一次，因此初始几个需要特殊返回
//自底向上构建，每次从当前长度出发，切一刀，选择一种切法使得乘积最大
class Solution {
public:
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        int maxMulti=0;
        for(int len=4;len<=n;++len)
        {
            maxMulti=0;
            for(int j=1;j<=len/2;++j)
            {
                maxMulti=max(maxMulti,dp[j]*dp[len-j]);
            }
            dp[len]=maxMulti;
        }
        return dp[n];
    }
};
