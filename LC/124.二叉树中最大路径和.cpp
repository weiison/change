//任一节点到任一节点，可以不经过根节点
class Solution {
public:
    int maxPathSum(TreeNode* root,int& allMax)
    {
        if(root==NULL) return 0;
        int left=maxPathSum(root->left,allMax);
        int right=maxPathSum(root->right,allMax);
        left=max(0,left);
        right=max(0,right);
        int nowSum=root->val+left+right;//以当前节点作为最高节点计算的值，左右子树都加上
        allMax=max(allMax,nowSum);
        int res=root->val+max(left,right);
        return res;//经过当前节点的最大路径和，左右子树只能选一个
    }
    int maxPathSum(TreeNode* root) {
        int allMax=INT_MIN;
        maxPathSum(root,allMax);
        return allMax;
    }
};
