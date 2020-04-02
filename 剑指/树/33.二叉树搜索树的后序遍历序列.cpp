class Solution {
public:
    bool verifyPostorder(vector<int>& postorder,int l,int r)
    {
        if(l>=r) return true;//到叶子节点都没出错，返回正确
        int i=l;
        for(;i<r;++i)
        {
            if(postorder[i]>postorder[r]) break;//找到第一个比根节点大的数
        }
        int j=i;
        for(;j<r;++j)
        {
            if(postorder[j]<postorder[r]) return false;
        }
        return verifyPostorder(postorder,l,i-1)&&verifyPostorder(postorder,i,r-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder,0,postorder.size()-1);
    }
};
