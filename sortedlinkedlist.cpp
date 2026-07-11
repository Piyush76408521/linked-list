// take an input from user of linked list and also sort the linked list in order and display it and also if the linked list is sorted then return true and if not then false and then sort it.
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
Node* insert(Node* head,int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
int isSorted(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->data>temp->next->data){
            return false;
        }
        temp=temp->next;
    }
    return true;
}
int main(){
    Node* head=NULL;
    int n,val;
    cout<<"Enter the number of elements in the linked list: ";
    cin>>n;
    cout<<"Enter the elements of the linked list: ";
    for(int i=0;i<n;i++){
        cin>>val;
        head=insert(head,val);
    }
    if(isSorted(head)){
        cout<<"The linked list is sorted."<<endl;
    }
    else{
        cout<<"The linked list is not sorted."<<endl;
        vector<int> arr;
        Node* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        sort(arr.begin(),arr.end());
        head=NULL;
        for(int i=0;i<arr.size();i++){
            head=insert(head,arr[i]);
        }
        cout<<"The sorted linked list is: ";
        temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
