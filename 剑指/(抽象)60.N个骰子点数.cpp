class Solution {
public:
    double pow(int base,int n)
    {
        double res=1.0;
        for(int i=0;i<n;++i)
        {
            res*=base;
        }
        return res;
    }
    vector<double> twoSum(int n) {
        vector<double> res;
        vector<vector<int>> pro(2,vector<int>(6*n+1,0));//下标对应数字的出现次数
        int flag=0;
        for(int i=1;i<=6;++i)
            pro[flag][i]=1;
        for(int k=2;k<=n;++k)//每次增加一个骰子
        {
            for(int i=0;i<k;++i)//把上上次的清零
                pro[1-flag][i]=0;
            for(int i=k;i<=6*k;++i)//本轮可能出现的所有和，最大为6*k
            {
                pro[1-flag][i]=0;
                for(int j=1;j<=i&&j<=6;++j)
                    pro[1-flag][i]+=pro[flag][i-j];//根据上轮次数加上本次 
                                                 //p[1-flag][n]=p[flag][n-1]+p[flag][n-2]...
            }
            flag=1-flag;
        }
        double tol=pow(6,n);
        for(int i=n;i<=6*n;++i)
        {
            double retio=(double)pro[flag][i]/tol;
            res.push_back(retio);
        }
        return res;
    }
};
