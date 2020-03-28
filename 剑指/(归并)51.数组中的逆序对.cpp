class Solution {
public:
    void merge(vector<int>& nums,vector<int>& copy,int start,int end,int& cnt)
    {
        if(start>=end) return;
        int mid=((end-start)>>1)+start;
        merge(nums,copy,start,mid,cnt);
        merge(nums,copy,mid+1,end,cnt);
        int i=mid,j=end,k=end;
        while(i>=start&&j>=mid+1)//从尾到头合并 统计逆序对
        {
            if(nums[i]>nums[j])
            {
                cnt+=j-mid;
                copy[k--]=nums[i--];
            }
            else
            {
                copy[k--]=nums[j--];
            }
        }
        while(i>=start)
            copy[k--]=nums[i--];
        while(j>=mid+1)
            copy[k--]=nums[j--];
        for(k=start;k<=end;++k)
            nums[k]=copy[k];
    }
    int reversePairs(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        vector<int> copy(size);
        int cnt=0;
        merge(nums,copy,0,size-1,cnt);
        return cnt;
    }
};
