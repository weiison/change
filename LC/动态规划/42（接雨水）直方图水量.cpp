//计算每一个直方图柱上方可以装水的量，累加
class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        if(size<=2) return 0;
        vector<int> rightMax(size);
        rightMax[size-1]=0;
        for(int i=size-2;i>=0;--i)
        {
            rightMax[i]=max(rightMax[i+1],height[i+1]);//每个位置对应的右边最大高度
        }
        int leftmax=0;//左边最大，遍历时更新
        int res=0;
        for(int i=0;i<size;++i)
        {
            int minOfmax=min(leftmax,rightMax[i]);
            if(minOfmax>height[i]) res+=minOfmax-height[i];//左右最大的最小值减去当前高度
            leftmax=max(leftmax,height[i]);
        }
        return res;
    }
};
