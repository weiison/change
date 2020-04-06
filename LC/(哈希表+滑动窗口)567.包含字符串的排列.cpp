//判断s2是否包含s1的任意一种排列
class Solution {
public:
    bool isMatch(vector<int>& mps1,vector<int>& mps2)
    {
        for(int i=0;i<26;++i)
        {
            if(mps1[i]!=mps2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> mps1(26,0);
        vector<int> mps2(26,0);
        for(int i=0;i<s1.size();++i)
        {
            ++mps1[s1[i]-'a'];
            ++mps2[s2[i]-'a'];
        }
        for(int i=0;i<s2.size()-s1.size();++i)//从s2头部开始，判断是否匹配，不匹配则更新移动窗口
        {
            if(isMatch(mps1,mps2)) return true;
            ++mps2[s2[i+s1.size()]-'a'];
            --mps2[s2[i]-'a'];
        }
        return isMatch(mps1,mps2);//最后一个尚未比较
    }
};
