// 1669. Merge In Between Linked Lists
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *temp = list1;
    for(int i=0;i<a-1;i++)
    {
        temp = temp->next;
    }
    ListNode *temp2 = temp;
    for(int i=0;i<b-a+2;i++)
    {
        temp2 = temp2->next;
    }
    temp->next = list2;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = temp2;
    return list1;
}
int main()
{
    // Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
    // Output: [10,1,13,1000000,1000001,1000002,5]
    ListNode *list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    ListNode *result = mergeInBetween(list1, 3, 4, list2);
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}