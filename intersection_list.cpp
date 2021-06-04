#include<iostream>

using namespace std;
//题目:https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
//null和nullptr的区别:https://zhuanlan.zhihu.com/p/79883965
//链表：https://blog.csdn.net/qq_43543789/article/details/111244485?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_baidulandingword-0&spm=1001.2101.3001.4242
//三目预算符-> 判断表达式？true时赋值：false时赋值
//思路：当两个链表到相交前的节点数量不相等的时候，两个遍历节点再相交前分别遍历了m和n，遍历完后指向另外链表的头，再次遍历到相交节点时，所过长度一致，因此可以成功判断
//思路二：可以使用hash表
struct ListNode
{
    int val;
    ListNode *next;
    //构造函数，用int x初始化
    ListNode(int x):val(x), next(NULL){}
};
class solution
{
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA=headA;
        ListNode *tempB=headB;
        if(headA == nullptr || headB ==nullptr)
        {
            return nullptr;
        }
       while(tempA!=tempB)
       {
           tempA=tempA==nullptr?headB:tempA->next;
           tempB=tempB==nullptr?headA:tempB->next;
       }
       return tempA;
    }
};

int main()
{
    return 0;
}