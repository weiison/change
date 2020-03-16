//动态规划 dp[i]记录以i结尾的最长子串，pos[256]记录某个字符上次出现的位置
//        根据上次出现的位置由dp[i-1]推出dp[i]
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        vector<int> dp(n,1);
        int pos[256];
        for(int i=0;i<256;++i)
            pos[i]=-1;
        int res=1;
        pos[s[0]-' ']=0;
        for(int i=1;i<n;++i)
        {
            int lastPos=pos[s[i]-' '];
            if(lastPos==-1||i-lastPos>dp[i-1]) dp[i]=dp[i-1]+1;//以i-1结尾最长子串中不含当前字符
            else dp[i]=i-lastPos;
            pos[s[i]-' ']=i;
            res=max(res,dp[i]);
        }
        return res;
    }
};
