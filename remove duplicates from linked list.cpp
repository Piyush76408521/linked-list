#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        Node*curr=head;
        while(curr!=NULL&&curr->next!=NULL){
            if(curr->data==curr->next->data){
                Node*temp=curr->next;
                curr->next=curr->next->next;
                delete(temp);
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};
int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    Solution solution;
    Node* newHead = solution.removeDuplicates(head);

    // Print the modified linked list
    Node* curr = newHead;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;

    // Free the memory
    curr = newHead;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
