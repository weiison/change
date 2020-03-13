class Solution {
public:
    bool isSubTree(TreeNode* A,TreeNode* B)//在根节点相同情况下，A是否和B结构一致
    {
        if(B==NULL) return true;
        if(A==NULL) return false;
        if(A->val==B->val)
        {
            return isSubTree(A->left,B->left)&&isSubTree(A->right,B->right);
        }
        else return false;
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==NULL||B==NULL) return false;
        bool res=false;
        if(A->val==B->val)//找到A中某个节点和B根节点相同
        {
            res=isSubTree(A,B);
        }
        if(!res)//一次比较失败，接着找，成功则不继续找
            res=isSubStructure(A->left,B);
        if(!res)
            res=isSubStructure(A->right,B);
        return res;
    }
};
