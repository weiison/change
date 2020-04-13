//要求O(log(m+n))时间复杂度，不能遍历每个元素，利用排好序这一条件
class Solution {
public:
    //两个数组中排在第k小的数字
    int getKth(vector<int>& nums1,int start1,int end1, vector<int>& nums2,int start2,int end2,int k)
    {
        int len1=end1-start1+1;
        int len2=end2-start2+1;
        if(len1>len2) return getKth(nums2,start2,end2,nums1,start1,end1,k);//确保是l1更小，如果数组为空一定是num1数组
        if(len1==0) return nums2[start2+k-1];
        if(k==1) return min(nums1[start1],nums2[start2]);//较小的那个数
        int i=start1+min(len1,k/2)-1;//二分k，当前两个数组要比较的数字，超过数组剩余长度则指向最后一个
        int j=start2+min(len2,k/2)-1;
        if(nums1[i]<nums2[j])//淘汰nums1的下标<=i的元素
            return getKth(nums1,i+1,end1,nums2,start2,end2,k-(i-start1+1));
        else
            return getKth(nums1,start1,end1,nums2,j+1,end2,k-(j-start2+1));
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        int len=len1+len2;
        double res;
        if(len%2==0)
        {
            res=0.5*(getKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,len/2)+getKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,len/2+1));
        }
        else
        {
            res=1.0*(getKth(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1,len/2+1));
        }
        return res;
    }
};
