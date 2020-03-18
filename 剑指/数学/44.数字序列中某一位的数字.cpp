/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。
*/
class Solution {
public:
    int powBase10(int n)
    {
        if(n==0) return 0;
        int res=1;
        for(int i=0;i<n;++i)
            res*=10;
        return res;
    }
    int countNum(int digit)
    {
        int res=1;
        if(digit==1) return 10;
        else
        {
            for(int i=1;i<digit;++i)
            {
                res*=10;
            }
            res*=9;
        }
        return res;
    }
    int findNthDigit(int n,int digit)
    {
        int a=powBase10(digit-1)+n/digit;
        int b=n%digit;
        string temp=to_string(a);
        int res=temp[b]-'0';
        return res;
    }
    int findNthDigit(int n) {
        int digit=1;
        long long curN=n;
        int res;
        while(1)
        {
            int count=countNum(digit);//0-10，10-99，100-999中数字个数
            if(curN<(long long)count*(long long)digit)
            {
                res=findNthDigit(curN,digit);//在当前范围内找到对应位置的数字
                break;
            }   
            curN-=count*digit;
            ++digit;
        }
        return res;
    }
};
