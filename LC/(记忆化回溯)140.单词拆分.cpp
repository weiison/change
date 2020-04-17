class Solution {
public:
    vector<string> dfs(string& s,int cur,unordered_set<string>& st,unordered_map<int,vector<string>>& mp)
    {
        if(mp.find(cur)!=mp.end())
        {
            return mp[cur];
        }
        vector<string> res;
        if(cur==s.size())
            res.push_back("");//确保res里面有元素
        else
        {
            for(int i=cur;i<s.size();++i)
            {
                string strtmp=s.substr(cur,i-cur+1);
                if(st.find(strtmp)!=st.end())
                {
                    vector<string> tmp=dfs(s,i+1,st,mp);//获得之后的拆分结果
                    for(int i=0;i<tmp.size();++i)
                    {
                        res.push_back(strtmp+(tmp[i].empty()?"":" ")+tmp[i]);//要区分是否到达末尾，末尾tmp里面只有一个元素为""
                    }
                }
            }
        }
        mp[cur]=res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        unordered_map<int,vector<string>> mp;//当前下标位置的结果
        res=dfs(s,0,st,mp);
        return res;
    }
};
