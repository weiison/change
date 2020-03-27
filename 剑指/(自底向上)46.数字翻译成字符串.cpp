/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/
class Solution {
public:
    int translateNum(string& s)
    {
        int size=s.size();
        int cnt=0;
        vector<int> cnts(size);//记录当前位可以排出几种
        for(int i=size-1;i>=0;--i)
        {
            if(i<size-1) cnt=cnts[i+1];//继承后面排的次数，至少有这么多
            else cnt=1;//继承不到则加上一种
            if(i<size-1)
            {
                int digit1=s[i]-'0';
                int digit2=s[i+1]-'0';
                int number=digit1*10+digit2;
                if(number>=10&&number<=25)
                {
                    if(i<size-2) cnt+=cnts[i+2];//两位看成一位，继承之后的次数
                    else cnt+=1;//继承不到则加上一种
                }
            }
            cnts[i]=cnt;
        }
        cnt=cnts[0];
        return cnt;//到达首位，所有次数计算完毕
    }
    int translateNum(int num) {
        string s=to_string(num);
        return translateNum(s);
    }
};
