class Solution {
public:
    ListNode* mergeSortList(ListNode* head)
    {
        if(head==NULL||head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* p2=mergeSortList(slow->next);
        slow->next=NULL;//先排后半部分的，断开前面的再排前半部分
        ListNode* p1=mergeSortList(head);
        ListNode* p0=new ListNode(0);
        ListNode* p=p0;
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1->val<p2->val)
            {
                p->next=p1;
                p1=p1->next;
                p=p->next;
            }
            else
            {
                p->next=p2;
                p2=p2->next;
                p=p->next;                
            }
        }
        if(p1!=NULL)
            p->next=p1;
        if(p2!=NULL)
            p->next=p2;
        p=p0->next;
        delete p0;
        return p;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return head;
        ListNode*res=mergeSortList(head);
        return res;
    }
};
