//前序遍历所有路径，符合路径放入结果数组，不符合在路径数组中删除本层节点，返回父节点
class Solution {
public:
    void pathSumCore(TreeNode* root,vector<vector<int>>& res,vector<int>& path,int curSum,int sum)
    {
        curSum+=root->val;
        path.push_back(root->val);
        bool isleaf=root->left==nullptr&&root->right==nullptr;
        if(curSum==sum&&isleaf)//相等且为叶子节点
        {
            res.push_back(path);
        }
        if(root->left!=nullptr) pathSumCore(root->left,res,path,curSum,sum);
        if(root->right!=nullptr) pathSumCore(root->right,res,path,curSum,sum);
        path.pop_back();//path不是引用可以去掉此行
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(root==nullptr) return res;
        pathSumCore(root,res,path,0,sum);
        return res;
    }
};
