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

int count(Node *p)
{
    if(p == nullptr)
    {
        return 0;
    }
    else
    {
        return count(p->next) + 1;
    }
}

// Method 1: Using count - O(3n/2) traversals
int findMiddleByCount(Node* head)
{
    if(head == nullptr)
    {
        cout<<"List is empty!"<<endl;
        return -1;
    }
    
    int totalNodes = count(head);
    int middlePosition = (totalNodes / 2) + 1;
    
    Node* temp = head;
    for(int i = 1; i < middlePosition; i++)
    {
        temp = temp->next;
    }
    
    return temp->data;
}
int findMiddleByTwoPointer(Node* head)
{
    if(head == nullptr)
    {
        cout<<"List is empty!"<<endl;
        return -1;
    }
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
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

int main()
{
    cout<<"FIND MIDDLE OF LINKED LIST"<<endl;
    
    
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    
    Node* head1 = createList(arr1, size1);
    display(head1);
    
    cout<<"Middle (using count method): "<<findMiddleByCount(head1)<<endl;
    cout<<"Middle (using two pointer method): "<<findMiddleByTwoPointer(head1)<<endl;


    
    return 0;
}
