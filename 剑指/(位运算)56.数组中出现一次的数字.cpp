//数组中只有一个数字出现了1次，其余出现了3次（可以改为n次）
//计算32位每一位1出现的次数，对某一位来说，不能被3整除则目标数字该位为1，由位数组恢复求出数字
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitsum(32,0);//每一位1的总和
        int size=nums.size();
        for(int i=0;i<size;++i)
        {
            unsigned int bitMask=1;//移动到某一位做&
            for(int j=31;j>=0;--j)//bitsum数组存的位 0-31 对应 高-低
            {
                int bit=nums[i]&bitMask;
                if(bit) bitsum[j]+=1;
                bitMask=bitMask<<1;
            }
        }
        int res=0;
        for(int i=0;i<32;++i)
        {
            res=res<<1;
            res+=bitsum[i]%3;
        }
        return res;

    }
};
