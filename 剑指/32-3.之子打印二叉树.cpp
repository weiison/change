class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr) return res;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        int cnt=1;
        s1.push(root);
        while(!s1.empty()||!s2.empty())
        {
            vector<int> temp;
            if(cnt%2==1)
            {
                while(!s1.empty())
                {
                    TreeNode* now=s1.top();
                    s1.pop();
                    temp.push_back(now->val);
                    if(now->left!=nullptr) s2.push(now->left);
                    if(now->right!=nullptr) s2.push(now->right);
                }
                ++cnt;
            }
            else
            {
                while(!s2.empty())
                {
                    TreeNode* now=s2.top();
                    s2.pop();
                    temp.push_back(now->val);
                    if(now->right!=nullptr) s1.push(now->right);
                    if(now->left!=nullptr) s1.push(now->left);
                }
                ++cnt;
            }
            res.push_back(temp);
        }
        return res;
    }
};
