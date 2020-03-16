//统计一个数字在排序数组中出现的次数, 排序：二分查找，找到第一个和最后一个位置
class Solution {
public:
    int findFirst(vector<int>& nums,int target,int l,int r)
    {
        if(l>r) return -1;
        int mid=((r-l)>>1)+l;
        if(nums[mid]==target)
        {
            if(mid==0||(mid>0&&nums[mid-1]!=target)) return mid;
            return findFirst(nums,target,l,mid-1);
        }
        else if(nums[mid]>target) return findFirst(nums,target,l,mid-1);
        else return findFirst(nums,target,mid+1,r); 
    }
    int findLast(vector<int>& nums,int target,int l,int r)
    {
        if(l>r) return -1;
        int mid=((r-l)>>1)+l;
        if(nums[mid]==target)
        {
            if(mid==nums.size()-1||(mid<nums.size()-1&&nums[mid+1]!=target)) return mid;
            return findLast(nums,target,mid+1,r);
        }
        else if(nums[mid]>target) return findLast(nums,target,l,mid-1);
        else return findLast(nums,target,mid+1,r); 
    }    
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int first=findFirst(nums,target,0,nums.size()-1);
        int last=findLast(nums,target,0,nums.size()-1);
        if(first==-1&&last==-1) return 0;
        else return last-first+1;
    }
};

//0~n-1缺失数字 [0,1]缺2 [0,2]缺1 
//二分查找 找到第一个下标与数字不同的数，该下标极为缺失数字
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size=nums.size();
        int l=0,r=size-1;
        while(l<=r)
        {
            int mid=((r-l)>>1)+l;
            if(nums[mid]!=mid)
            {
                if(mid==0||nums[mid-1]==mid-1) return mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        if(l==size) return size;//！！！若所有下标均等于数字，则l会走到size 此时缺失的是size
        return -1;
    }
};
