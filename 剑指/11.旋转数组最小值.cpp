//法一：二分查找判断拐点在哪边，若首位元素相同
class Solution {
public:
    int inorder(vector<int> v,int l,int r)
    {
        int res=v[l];
        for(int i=l+1;i<=r;++i)
            res=min(res,v[i]);
        return res;
    }
    int minArray(vector<int>& numbers) {
        int n=numbers.size();
        if(n==0) return -1;
        int l=0,r=n-1;
        int mid=l;
        while(numbers[l]>=numbers[r])//不满足则数组未旋转
        {
            if(r-l==1)//直到l,r相差一则找到
            {
                mid=r;
                break;
            }
            mid=((r-l)>>1)+l;
            if(numbers[mid]==numbers[l]&&numbers[mid]==numbers[r])
                return inorder(numbers,l,r);
            if(numbers[mid]>=numbers[l]) l=mid;
            else if(numbers[mid]<=numbers[r]) r=mid;
        }
        return numbers[mid];
    }
};
//法二：遍历数组找到拐点
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n=numbers.size();
        if(n==0) return -1;
        int res=numbers[0];
        for(int i=0;i<n-1;++i)
        {
            if(numbers[i]>numbers[i+1])
            {
                res=numbers[i+1];
                break;
            }
        }
        return res;
    }
};
