class Solution {
public:
    //后序遍历，判断左右子树是不是平衡，是则计算左右子树高度差，若差值绝对值小于等于1，则更新当前节点深度值，同时返回真；
    //                        左右子树至少有一个不平衡     或者左右子树平衡但与当前节点构成的树不平衡        返回假。
    bool isBalancedCore(TreeNode* root,int & depth)
    {
        if(root==nullptr) 
        {
            depth=0;
            return true;
        }
        int left,right;
        if(isBalancedCore(root->left,left)&&isBalancedCore(root->right,right))
        {

            int dif=left-right;
            if(dif>=-1&&dif<=1)
            {
                depth=left>right?left+1:right+1;
                return true;
            }
        }
        return false;
    }
    bool isBalanced(TreeNode* root) {
        int depth=0;
        return isBalancedCore(root,depth);
    }
};
