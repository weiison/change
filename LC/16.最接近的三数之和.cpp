//排序，固定一个数字，然后根据三数之和调整首尾指针
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=nums[0]+nums[1]+nums[n-1];
        for(int i=0;i<n;++i)
        {
            int start=i+1;
            int end=n-1;
            while(start<end)
            {
                int ans=nums[i]+nums[start]+nums[end];
                if(abs(target-ans)<abs(target-res)) res=ans;
                if(ans>target) --end;
                else if(ans<target) ++start;
                else return res;
            }
        }
        return res;
    }
};
