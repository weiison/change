struct Env{
    int w;
    int h;
    Env():w(0),h(0){}
    Env(int a,int b):w(a),h(b){}
};
bool cmp(Env a,Env b)//按w升序排，若w相同，按h降序排
{
    if(a.w==b.w) return a.h>b.h;
    else return a.w<b.w;
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0) return 0;
        vector<Env> env(n);
        for(int i=0;i<n;++i)
        {
            env[i].w=envelopes[i][0];
            env[i].h=envelopes[i][1];
        }
        sort(env.begin(),env.end(),cmp);
        int res=1;
        vector<int> dp(n,0);//以i结尾的最长子序列
        dp[0]=1;
        for(int i=1;i<n;++i)//对h寻找最长递增子序列则为结果
        {
            int maxval=0;
            for(int j=0;j<i;++j)
            {
                if(env[i].h>env[j].h)
                {
                    maxval=max(maxval,dp[j]);
                }
            }
            dp[i]=maxval+1;//找到前一个比i小的数中最长的子序列，继承他的子序列加上i本身
            res=max(res,dp[i]);
        }
        return res;
    }
};
