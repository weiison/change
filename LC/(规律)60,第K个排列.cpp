class Solution {
public:
    int fac(int n)//n!
    {
        int res=1;
        for(int i=n;i>1;i--)
            res*=i;
        return res;
    }
    string getPermutation(int n, int k) {
        string s=string("123456789").substr(0,n);
        --k;
        string res;
        while(k)
        {
            int i=k/fac(n-1);//当前第一个所在位置
            res+=s[i];
            s.erase(i,1);//删去已加入的
            k%=fac(n-1);
            --n;
        }
        return res+s;

    }
};
