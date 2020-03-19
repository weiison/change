//16次方拆成8次方乘8次方 以此类推
class Solution {
public:
    double myUnsignedPow(double x,unsigned int n)
    {
        if(n==1) return x;
        if(n==0) return 1.0;
        double res;
        res=myPow(x,n>>1);
        res*=res;
        if(n&1==1) res*=x;//奇数次方再乘一次底数
        return res;
    }
    double myPow(double x, int n) {
        if(x==0) return 0;
        double res;
        unsigned int exp;
        if(n>=0)
            exp=n;
        else
            exp=-(unsigned int)n;
        res=myUnsignedPow(x,exp);
        if(n<0) res=1.0/res;    
        return res;

    }

};
