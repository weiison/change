class Solution {
public:
    //先找路径，再找最后一个公共点
    bool findPath(TreeNode* root,TreeNode* p,vector<TreeNode*>& path)
    {               
        if(root==nullptr) return false; 
        path.push_back(root);
        if(root==p) return true;
        bool found=false;
        found=findPath(root->left,p,path);
        if(!found) found=findPath(root->right,p,path);
        if(!found) path.pop_back();
        return found;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findPath(root,p,path1);
        findPath(root,q,path2);
        int i=0;
        while(i<path1.size()&&i<path2.size()&&path1[i]==path2[i])
            ++i;
        return path1[i-1];
    }
};
