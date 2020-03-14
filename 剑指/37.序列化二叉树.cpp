class Codec {
public:
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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        encode(root,res);
        return res;
    }
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
        now->left=decode(data,p);
        now->right=decode(data,p);
        return now;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int p=0;
        TreeNode* root=decode(data,p);
        return root;
    }

};
