class Solution {
public:
    bool isValid(string ip)//长度在1-3之间的字符串是不是合法IP
    {
        int num=stoi(ip);
        if(num>255) return false;
        if(ip.size()>=2&&ip[0]=='0') return false;
        return true;
    }
    void dfs(string& s,int pos,vector<string>& path,vector<string>& res)
    {
        int maxLen=(4-path.size())*3;
        if(s.size()-pos>maxLen) return;
        if(pos==s.size()&&path.size()==4)
        {
            string temp="";
            for(int i=0;i<4;++i)
            {
                temp+=path[i];
                if(i!=3) temp+=".";
            }
            res.push_back(temp);
            return;
        }
        for(int i=pos;i<s.size()&&i<=pos+2;++i)//从当前位置最多找三个 
        {
            string ip=s.substr(pos,i-pos+1);
            if(isValid(ip))//找到一个合法ip 在此基础上继续找
            {
                path.push_back(ip);
                dfs(s,i+1,path,res);
                path.pop_back();//返回时删除
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()==0||s.size()<4) return res;
        vector<string> path;
        dfs(s,0,path,res);
        return res;
    }
};
