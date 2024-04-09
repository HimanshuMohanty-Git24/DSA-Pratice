// 143. Reorder List
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void reorderList(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* prev = NULL;
    while(slow!=NULL)
    {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    ListNode* first = head;
    ListNode* second = prev;
    while(second->next!=NULL)
    {
        ListNode* temp = first->next;
        first->next = second;
        first = temp;
        temp = second->next;
        second->next = first;
        second = temp;
    }
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    reorderList(head);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    return 0;
}
