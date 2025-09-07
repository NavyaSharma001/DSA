#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void display(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<"->";
        display(p->next);
    }
    else
    {
        cout<<"NULL"<<endl;
    }
}

// Method 1: Iterative approach to reverse linked list
Node* reverseIterative(Node* head)
{
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    
    while(current != nullptr)
    {
        next = current->next;   // Store next node
        current->next = prev;   // Reverse the link
        prev = current;         // Move prev one step ahead
        current = next;         // Move current one step ahead
    }
    
    return prev; // prev becomes the new head
}



Node* createList(int arr[], int size)
{
    if(size == 0) return nullptr;
    
    Node* head = new Node;
    head->data = arr[0];
    head->next = nullptr;
    
    Node* last = head;
    Node* temp;
    
    for(int i = 1; i < size; i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    
    return head;
}

// Helper function to copy a linked list
Node* copyList(Node* head)
{
    if(head == nullptr) return nullptr;
    
    Node* newHead = new Node;
    newHead->data = head->data;
    newHead->next = nullptr;
    
    Node* newCurrent = newHead;
    Node* current = head->next;
    
    while(current != nullptr)
    {
        Node* newNode = new Node;
        newNode->data = current->data;
        newNode->next = nullptr;
        newCurrent->next = newNode;
        newCurrent = newNode;
        current = current->next;
    }
    
    return newHead;
}

int main()
{
    cout<<"REVERSE LINKED LIST"<<endl;
    
    // Test with example: 1->2->3->4->NULL
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    Node* originalHead = createList(arr, size);
    cout<<"Original Linked List: ";
    display(originalHead);
    
    // Method 1: Iterative reversal
    Node* head1 = copyList(originalHead);
    cout<<"\n Method 1: Iterative Approach "<<endl;
    cout<<"Before reversal: ";
    display(head1);
    head1 = reverseIterative(head1);
    cout<<"After reversal: ";
    display(head1);
    

    
    return 0;
}