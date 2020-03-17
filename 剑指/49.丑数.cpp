//multi2记录最右一个×2大于当前值的下标，每次从三个下标x2,x3,x5中选最小值为下一个丑数
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n,1);
        int multi2=0,multi3=0,multi5=0;
        int i=1;
        while(i<n)
        {
            ugly[i]=min(min(2*ugly[multi2],3*ugly[multi3]),5*ugly[multi5]);
            while(ugly[i]>=2*ugly[multi2])
                ++multi2;
            while(ugly[i]>=3*ugly[multi3])
                ++multi3;
            while(ugly[i]>=5*ugly[multi5])
                ++multi5;
            ++i;            
        }
        return ugly[n-1];
    }
};
