//输入字符串"I am a student. "，则输出"student. a am I"
//输入首位有空格，或者中间有多个个空格，要删去
class Solution {
public:
    //翻转指定范围内的字符串
    void reverse(string& s,int start,int end)
    {
        while(start<end)
        {
            swap(s[start],s[end]);
            ++start;
            --end;
        }
    }
    //删除多余空格
    void change(string& s)
    {
        while(s[0]==' ') s.erase(0,1);
        while(s[s.size()-1]==' ') s.erase(s.size()-1,1);
        int i=0;
        //此时首尾无空格
        while(i<s.size())
        {
            if(s[i]==' '&&s[i+1]==' ')
                while(s[i]==' '&&s[i+1]==' ')
                    s.erase(i+1,1);
            ++i;
        }
    }
    string reverseWords(string s) {
        change(s);
        reverse(s,0,s.size()-1);
        int start=0;
        int end=0;
        while(end<s.size())
        {
            if(s[end]!=' ' )
            {
                ++end;
            }
            else
            {
                reverse(s,start,end-1);
                ++end;
                start=end;
            }
        }
        if(start!=end) reverse(s,start,end-1);
        return s;
    }
};
