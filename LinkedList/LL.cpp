//Linkedlist
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1)//constructor
    {
        data=data1;
        next=next1;
    }
    Node(int data1)//constructor
    {
        data=data1;
        next=NULL;
    }
    ~Node(){//destructor
        delete next;
    }
};
int main()
{
    Node* head=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    head->next=second;
    second->next=third;
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
   return 0;
}