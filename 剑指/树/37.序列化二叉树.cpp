class Codec {
public:
    //前序遍历输出字符串
    void encode(TreeNode* root,string& res)
    {
        if(root==nullptr) 
        {
            res+="$,";
            return;
        }
        res+=to_string(root->val)+",";
        encode(root->left,res);
        encode(root->right,res);
    }
    string serialize(TreeNode* root) {
        string res;
        encode(root,res);
        return res;
    }
    //读取字符串 前序遍历构建树
    TreeNode* decode(string& data,int & p)
    {
        if(data[p]=='$')
        {
            p+=2;
            return nullptr;
        }
        bool flag=false;
        if(data[p]=='-')
        {
            flag=true;//是负数
            p+=1;
        }
        int num=0;
        while(data[p]!=',')
        {
            num=num*10+(data[p]-'0');
            ++p;
        }
        if(flag) num=-num;
        ++p;
        TreeNode* now=new TreeNode(num);
        if(p<data.size()) now->left=decode(data,p);
        if(p<data.size()) now->right=decode(data,p);
        return now;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p=0;
        TreeNode* root=decode(data,p);
        return root;
    }

};
