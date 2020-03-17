class Solution {
public:
    int powBase10(int n)
    {
        int res=1;
        for(int i=0;i<n;++i)
            res*=10;
        return res;
    }
    int numOf1(string s,int begin)
    {
        if(s[begin]=='\0'||s.size()<=begin) return 0;
        int first=s[begin]-'0';
        int len=s.size()-begin;
        if(len==1&&first==0) return 0;
        if(len==1&&first>0) return 1;
        int numFirstDigit=0;//计算首位是1的所有次数
        if(first>1)
            numFirstDigit=powBase10(len-1);
        else if(first==1)//首位是0不计算！！如1080的子串，去掉1后为080
        {
            string temp=s.substr(begin+1,len-1);
            numFirstDigit=stoi(temp)+1;
        }
        int numOther=first*(len-1)*powBase10(len-2);//首位不是1其他位是1的次数
                                                   //首位大小（第一位次数）*剩下位数选一位是1*其余位数出现的排列组合
        int numSub=numOf1(s,begin+1);//递归处理去掉首位的子字符串
        return numFirstDigit+numOther+numSub;
    }
    int countDigitOne(int n) {
        string s=to_string(n);
        return numOf1(s,0);
    }
};
