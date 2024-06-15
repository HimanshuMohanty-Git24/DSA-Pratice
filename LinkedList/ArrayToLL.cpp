//Array to LL conversion
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
Node* convertArrayToLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;//meaning: that temp points to the last node of the list
    }
    return head;
}//TC: O(n)
int LengthOfLL(Node* head){
    int ctr=0;
    Node* temp = head;
    //Traverse
    while(temp!=NULL){
        temp=temp->next;
        ctr++;
    }
    return ctr;
}//TC: worst case: O(n) Best case: O(1)
bool findElementLL(Node* head,int key){
    Node* temp = head;
    //Traverse
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}//TC: Worst case: O(n) Best case: O(1)
int main()
{
    vector<int> arr = {12, 1, 3, 8};
    Node* head = convertArrayToLL(arr);
    Node* temp = head;
    //Traverse
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"length of LL:"<<LengthOfLL(head)<<endl;
    int x;
    cout<<"Find the element you want to search:";
    cin>>x;
    if(findElementLL(head,x)){
        cout<<"Yes "<<x<<" is present in the LL"<<endl;
    }
    else{
        cout<<"No "<<x<<" is not present in the LL"<<endl;
    }
    return 0;
}