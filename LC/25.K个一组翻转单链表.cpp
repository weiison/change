class Solution {
public:
    ListNode* reverseSingle(ListNode* head)
    {
        ListNode* pre=NULL;
        while(head!=NULL)
        {
            ListNode* next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p0=new ListNode(0);
        ListNode* pre=p0;//上一个已翻转链表的尾
        ListNode* start=head;//当前要翻转的起点
        ListNode* end=head;//当前要翻转的结束
        while(end!=NULL)
        {
            for(int i=1;i<k&&end!=NULL;++i) end=end->next;
            if(end==NULL) break;
            ListNode* next=end->next;
            end->next=NULL;//断开当前要翻转的部分
            reverseSingle(start);
            pre->next=end;
            start->next=next;
            pre=start;
            start=next;
            end=next;
        }
        pre=p0->next;
        delete p0;
        return pre;
    }
};
