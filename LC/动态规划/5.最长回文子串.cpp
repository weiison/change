class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len<2) return s;
        int maxlen=1;
        int start=0;
        vector<vector<bool>> dp(len,vector<bool>(len,false));//dp[i][j]表示起点下标为i终点为j子串是否是回文
        for(int i=0;i<len;++i)//长度为1的回文串
            dp[i][i]=true;
        for(int i=0;i<len-1;++i)//长度为2的回文串
        {
            if(s[i]==s[i+1]) 
            {
                dp[i][i+1]=true;
                maxlen=2;
                start=i;
            }
        }
        for(int l=3;l<=len;++l)
        {
            for(int i=0;i+l-1<len;++i)
            {
                int j=i+l-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==true)
                {
                    maxlen=l;
                    dp[i][j]=true;
                    start=i;
                }
            }
        }
        return s.substr(start,maxlen);

    }
};
