class Solution {
public:
    void treeToDoublyList(Node* cur,Node* &pLastNode)//中序遍历
    {
        if(cur==NULL) return;
        if(cur->left!=NULL)
            treeToDoublyList(cur->left,pLastNode);//当前节点左子树已经递归排成链表，pLastNode指向链表最后一个节点
        cur->left=pLastNode;
        if(pLastNode!=NULL) pLastNode->right=cur;//把当前节点添加进链表尾部
        pLastNode=cur;//当前节点成为已排好的链表最后一个节点
        if(cur->right!=NULL)
            treeToDoublyList(cur->right,pLastNode);//递归转换右子树
    }
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        Node* lastNode=NULL;
        treeToDoublyList(root,lastNode);
        Node* p=lastNode;
        while(p!=NULL&&p->left!=NULL)
        {
            p=p->left;
        }
        Node* head=p;
        head->left=lastNode;
        lastNode->right=head;
        return head;
    }
};
