class Solution {
public:
    TreeNode* helpBuildTree(vector<int>& preorder,vector<int>& inorder,int preL,int preR,int inL,int inR)
    {
        if(preL>preR) return NULL;
        TreeNode* root=new TreeNode(preorder[preL]);
        int k;
        for(k=inL;k<=inR;++k)
            if(inorder[k]==preorder[preL]) break;
        int len=k-inL;
        root->left=helpBuildTree(preorder,inorder,preL+1,preL+len,inL,k-1);
        root->right=helpBuildTree(preorder,inorder,preL+len+1,preR,k+1,inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=helpBuildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
        return root;
    }
};
