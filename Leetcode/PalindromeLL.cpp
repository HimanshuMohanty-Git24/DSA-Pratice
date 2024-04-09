//234. Palindrome Linked List
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
bool isPalindrome(ListNode* head) {
    vector<int> arr;
    while(head!=NULL)
    {
        arr.push_back(head->val);
        head = head->next;
    }
    int i=0,j=arr.size()-1;
    while(i<j)
    {
        if(arr[i]!=arr[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool isPali(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    //find the middle(slow)
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse the second half
    ListNode* prev = NULL;
    while(slow!=NULL)
    {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    //check if palindrome
    ListNode* left = head;
    ListNode* right = prev;
    while(right!=NULL)
    {
        if(left->val!=right->val)
            return false;
        left = left->next;
        right = right->next;
    }
    return true;
}
int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout<<isPalindrome(head);
   return 0;
}