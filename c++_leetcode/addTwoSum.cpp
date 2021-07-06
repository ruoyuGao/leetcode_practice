#include<iostream>
#include<vector>

using namespace std;
//https://leetcode-cn.com/problems/add-two-numbers/
//温习了链表的建立，记得留个头留个尾，记得new
struct ListNode{
	int val;
	ListNode *next;
	ListNode(): val(0),next(nullptr){}
	ListNode(int x): val(x),next(nullptr){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

class Solution{
	public:
	ListNode* addTwoNumber(ListNode* l1,ListNode* l2){
		ListNode *head=nullptr,*tail=nullptr;
		int next_digit=0;
		int temp;
		while(l1 != nullptr|| l2 !=nullptr)
		{
			
			int n1=l1?l1->val:0;
			int n2=l2?l2->val:0;
			temp=n1+n2+next_digit;
			next_digit=0;
			if(temp>=10)temp-=10,next_digit=1;
			if(!head)
			{
				head=tail=new ListNode(temp);
			}else{
				tail->next=new ListNode(temp);
				tail=tail->next;
			}
			if(l1)l1=l1->next;
			if(l2)l2=l2->next;
		}
		if(next_digit==1)tail->next=new ListNode(1);
		return head;
	}
	
};