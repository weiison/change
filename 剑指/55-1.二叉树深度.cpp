class Solution {
public:
    void DFS(TreeNode* root,int & curD,int & maxD)
    {
        if(root==nullptr)
        {
            maxD=max(curD,maxD);
            return;
        }
        ++curD;
        DFS(root->left,curD,maxD);
        DFS(root->right,curD,maxD);
        --curD;
    }
    int maxDepth(TreeNode* root) {
        /*方法一：遍历所有路径，记录最大的一个
        int maxD=-1;
        int curD=0;
        DFS(root,curD,maxD);
        return maxD;
        */
        //方法二，递归调用主函数，从左右子树选一个更深的加一
        if(root==nullptr) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return l>r?(l+1):(r+1);
    }
};
