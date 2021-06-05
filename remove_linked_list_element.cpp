/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    //递归也是个不错的方法，时间复杂度不变，不过写起来省事儿
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
         {
             return nullptr;
         }
         while(head->val==val)
         {
             if(head->next==nullptr)
             {
                 return nullptr;
             }
              head=head->next;
         }
         ListNode *q=head,*p=head;
         while(p->next!=NULL)
         {
             p=p->next;
             //ListNode *x;
             if(p->val==val)
             {
                 
                 q->next=p->next;
                 //不用delete，因为在链表的实现这里使用了堆栈结构，智能FILO或者反过来，不能释放单独节点的内存，因此这种方法不能单独delete节点
                 //第二种解释是这个链表的类型时有父类申请的，谁申请谁释放
                 //x=p;
                 //delete x;
             }
             else
             {
                 q=p;
             }
         }
         return head;
    }
};
