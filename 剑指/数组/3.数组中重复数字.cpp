//找出数组中重复的数字。
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
//也不知道每个数字重复了几次。请找出数组中任意一个重复的数字

//遍历整个数组，若当前值不等于下标，则一直将当前值 和 以当前值为下标的数组元素交换 直至当前数等于下标 过程中若找到重复数字则返回 
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int res;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i)
            {
                if(nums[i]==nums[nums[i]])
                {
                    res=nums[i];
                    break;
                }
                swap(nums[i],nums[nums[i]]);
            }
        }
        return res;
    }
};
